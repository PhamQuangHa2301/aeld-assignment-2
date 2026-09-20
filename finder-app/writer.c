#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd;
    ssize_t nr;
    const char *writefile;
    const char *writestr;

    openlog(NULL, 0, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments");
        closelog();
        return 1;
    }

    writefile = argv[1];
    writestr = argv[2];

    fd = open(writefile, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        syslog(LOG_ERR, "Failed to open file %s: %s",
               writefile, strerror(errno));
        closelog();
        return 1;
    }

    nr = write(fd, writestr, strlen(writestr));

    if (nr == -1) {
        syslog(LOG_ERR, "Failed to write to file %s: %s",
               writefile, strerror(errno));
        close(fd);
        closelog();
        return 1;
    }

    if (close(fd) == -1) {
        syslog(LOG_ERR, "Failed to close file %s: %s",
               writefile, strerror(errno));
        closelog();
        return 1;
    }

    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    closelog();

    return 0;
}