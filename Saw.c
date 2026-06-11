#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

/* ── Forward declarations ─────────────────────────────────────── */
void display_header(void);
void handle_ping_options(void);
void flush_stdin(void);

void flush_stdin(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void display_header(void)
{
    system("cls");
    printf("============================================\n");
    printf("        SYSTEM TOOLS DASHBOARD              \n");
    printf("============================================\n\n");
}

static int is_valid_ping_target(const char *addr)
{
    if (addr == NULL || addr[0] == '\0') return 0;

    for (int i = 0; addr[i] != '\0'; i++) {
        char c = addr[i];
        int is_alnum  = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
                        || (c >= '0' && c <= '9');
        int is_symbol = (c == '.' || c == '-' || c == '_');
        if (!is_alnum && !is_symbol) return 0;
    }
    return 1;
}

static void run_ping(const char *target)
{
    char command[200];
    snprintf(command, sizeof(command), "ping %s", target);
    printf("\n");
    system(command);
}

void handle_ping_options(void)
{
    int ping_choice;

    printf("\n--------------------------------------------\n");
    printf("  PING TOOLS\n");
    printf("--------------------------------------------\n");
    printf("  [1] Internal test    (loopback 127.0.0.1)\n");
    printf("  [2] External / target ping  (custom IP or hostname)\n");
    printf("  [0] Back to main menu\n");
    printf("--------------------------------------------\n");
    printf("  Your choice: ");

    if (scanf("%d", &ping_choice) != 1) {
        printf("\n Error: Please enter a valid number.\n");
        flush_stdin();
        return;
    }
    flush_stdin();

    switch (ping_choice) {

    case 1:
        printf("\n Running internal loopback test (127.0.0.1)...\n");
        printf(" This checks whether your local TCP/IP stack is healthy.\n");
        run_ping("127.0.0.1");

        printf("\n Loopback test complete.\n");
        printf(" * All replies received  → TCP/IP stack is healthy.\n");
        printf(" * Request timed out     → Network adapter / stack issue.\n");
        break;

      case 2: {
        char target[128];

        printf("\n Enter target IP address or hostname\n");
        printf(" (e.g.  8.8.8.8  or  google.com): ");

        if (scanf("%127s", target) != 1) {
            printf("\n Error: Invalid input.\n");
            flush_stdin();
            break;
        }
        flush_stdin();

        if (!is_valid_ping_target(target)) {
            printf("\n Error: Address contains illegal characters.\n");
            printf(" Allowed: letters, digits, '.', '-', '_'\n");
            break;
        }

        printf("\n Pinging external target: %s\n", target);
        printf(" This tests outbound connectivity from your machine.\n");
        run_ping(target);

        printf("\n External ping complete.\n");
        printf(" * All replies received  → Connection to target is healthy.\n");
        printf(" * Request timed out     → Target unreachable or blocking ICMP.\n");
        printf(" * General failure       → Check your internet connection.\n");
        break;
    }

    case 0:
        printf("\n Returning to main menu...\n");
        break;

    default:
        printf("\n Invalid option. Returning to main menu.\n");
        break;
    }
}

/* ================================================================
                          main
 * ================================================================ */
int main(void)
{
    int user_selection;

    while (1) {

        display_header();

        printf("Dear User, choose what you want to do:\n\n");
        printf("  [1] Network configuration (ipconfig)\n");
        printf("  [2] View running processes (tasklist)\n");
        printf("  [3] System shutdown\n");
        printf("  [4] Network ping tools\n");
        printf("  [5] Exit to dashboard\n\n");
        printf("  Your choice: ");

        if (scanf("%d", &user_selection) != 1) {
            printf("\n Error: Dear User, please enter a valid number.\n");
            flush_stdin();
            _getch();
            system("cls");
            continue;
        }
        flush_stdin();

        switch (user_selection) {

        case 1:
            printf("\n... Fetching your network details, please wait ...\n\n");
            system("ipconfig");
            break;

        case 2:
            printf("\n... Fetching your active task list, please wait ...\n\n");
            system("tasklist");
            break;

        case 3: {
            int seconds_remaining  = 60;
            int shutdown_cancelled = 0;

            system("shutdown /s /t 60");

            printf("\n !!! Your system shutdown has been initiated !!! \n");
            printf(" You have 60 seconds to cancel.\n");
            printf(" Press 'C' to cancel / abort the shutdown.\n\n");

            while (seconds_remaining > 0) {
                printf("\r Shutting down in: %2d second(s)...   ",
                       seconds_remaining);
                fflush(stdout);

                if (_kbhit()) {
                    char key = (char)_getch();
                    if (key == 'c' || key == 'C') {
                        system("shutdown /a");
                        printf("\n\n Shutdown successfully cancelled.\n");
                        shutdown_cancelled = 1;
                        break;
                    }
                }

                Sleep(1000);
                seconds_remaining--;
            }

            if (!shutdown_cancelled && seconds_remaining == 0) {
                printf("\n\n Time's up! The system will shut down momentarily.\n");
            }
            break;
        }

        case 4:
            handle_ping_options();
            break;

        case 5:
            printf("\n Dashboard closing. Have a productive day!\n\n");
            return 0;

        default:
            printf("\n Selection not recognized. Please try again.\n");
            break;

        } /* end switch */

        printf("\n Task completed.");
        printf("\n Press any key to return to the menu...\n");
        _getch();
        system("cls");

    }

    return 0;
}
