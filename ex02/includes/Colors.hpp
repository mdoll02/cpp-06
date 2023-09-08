#ifndef COLORS_H
# define COLORS_H

#define R   "\033[0m"
#define BLACK   "\033[30m"                /* Black */
#define RED     "\033[31m"                /* Red */
#define GREEN   "\033[32m"                /* Green */
#define YELLOW  "\033[33m"                /* Yellow */
#define BLUE    "\033[34m"                /* Blue */
#define MAGENTA "\033[35m"                /* Magenta */
#define CYAN    "\033[36m"                /* Cyan */
#define WHITE   "\033[37m"                /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define BASE_T "\033[38;5;"
#define BASE_B "\033[48;5;"

#define    SYS_MSG_DES " \033[38;5;242m❯ \033[3m\033[38;5;242m\033[38;5;124m"
#define    SYS_MSG_CON " \033[38;5;242m❯ \033[3m\033[38;5;242m\033[38;5;28m"
#define    SYS_MSG "\033[38;5;242m❯ \033[3m\033[38;5;242m"
#define    SYS_MSG_B "\033[48;5;242m❯ \033[3m\033[38;5;242m "
#define G "\033[38;5;242m"
#define SYS "\033[38;5;242m\033[4m\033[38;5;33m"
#define INFO "\033[48;5;39m[ INFORMATION ]\033[0m \033[38;5;123m"
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
#define P_DEBUG "\033[48;5;202m              [ DEBUGGING ]            \033[0m"

#endif