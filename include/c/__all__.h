#include "AT_BASE.h"
#if defined(__linux__)
#  include "AT_BASE_PLATFORM.h"
#  include "AT_CLKTCK.h"
#endif
#include "AT_EGID.h"
#include "AT_ENTRY.h"
#include "AT_EUID.h"
#include "AT_EXECFD.h"
#if defined(__linux__)
#  include "AT_EXECFN.h"
#endif
#include "AT_FLAGS.h"
#include "AT_GID.h"
#if defined(__linux__)
#  include "AT_HWCAP.h"
#  include "AT_HWCAP2.h"
#endif
#include "AT_IGNORE.h"
#include "AT_NOTELF.h"
#include "AT_NULL.h"
#include "AT_PAGESZ.h"
#include "AT_PHDR.h"
#include "AT_PHENT.h"
#include "AT_PHNUM.h"
#if defined(__linux__)
#  include "AT_PLATFORM.h"
#  include "AT_RANDOM.h"
#  include "AT_SECURE.h"
#endif
#include "AT_UID.h"
#include "CHAR_BIT.h"
#include "CHAR_MAX.h"
#include "CHAR_MIN.h"
#include "CLD_CONTINUED.h"
#include "CLD_DUMPED.h"
#include "CLD_EXITED.h"
#include "CLD_KILLED.h"
#include "CLD_STOPPED.h"
#include "CLD_TRAPPED.h"
#include "CLOCK_REALTIME.h"
#include "DT_BLK.h"
#include "DT_CHR.h"
#include "DT_DIR.h"
#include "DT_FIFO.h"
#include "DT_LNK.h"
#include "DT_REG.h"
#include "DT_SOCK.h"
#include "DT_UNKNOWN.h"
#include "E2BIG.h"
#include "EACCES.h"
#include "EADDRINUSE.h"
#include "EADDRNOTAVAIL.h"
#include "EAGAIN.h"
#include "EALREADY.h"
#include "EBADF.h"
#include "EBADMSG.h"
#include "EBUSY.h"
#include "ECANCELED.h"
#include "ECHILD.h"
#include "ECONNABORTED.h"
#include "ECONNREFUSED.h"
#include "ECONNRESET.h"
#include "EDEADLK.h"
#include "EDESTADDRREQ.h"
#include "EDOM.h"
#include "EDQUOT.h"
#include "EEXIST.h"
#include "EFAULT.h"
#include "EFBIG.h"
#include "EHOST.h"
#include "EIDRM.h"
#include "EILSEQ.h"
#include "EINPROGRESS.h"
#include "EINTR.h"
#include "EINVAL.h"
#include "EIO.h"
#include "EISCONN.h"
#include "EISDIR.h"
#if defined(__linux__)
#  include "ELIBBAD.h"
#endif
#include "ELOOP.h"
#include "EMFILE.h"
#include "EMLINK.h"
#include "EMSGSIZE.h"
#include "ENAMETOOLONG.h"
#include "ENETDOWN.h"
#include "ENETRESET.h"
#include "ENETUNREACH.h"
#include "ENFILE.h"
#include "ENOBUFS.h"
#include "ENODATA.h"
#include "ENODEV.h"
#include "ENOENT.h"
#include "ENOEXEC.h"
#include "ENOLCK.h"
#include "ENOLINK.h"
#include "ENOMEM.h"
#include "ENOMSG.h"
#include "ENOPROTOOPT.h"
#include "ENOSPC.h"
#include "ENOSR.h"
#include "ENOSYS.h"
#include "ENOTBLK.h"
#include "ENOTCONN.h"
#include "ENOTDIR.h"
#include "ENOTEMPTY.h"
#include "ENOTRECOVERABLE.h"
#include "ENOTSOCK.h"
#include "ENOTSUP.h"
#include "ENOTTY.h"
#include "ENXIO.h"
#include "EOF.h"
#include "EOPNOTSUPP.h"
#include "EOVERFLOW.h"
#include "EOWNERDEAD.h"
#include "EPERM.h"
#include "EPIPE.h"
#if defined(__linux__)
#  include "EPOLLERR.h"
#  include "EPOLLET.h"
#  include "EPOLLHUP.h"
#  include "EPOLLIN.h"
#  include "EPOLLONESHOT.h"
#  include "EPOLLOUT.h"
#  include "EPOLLPRI.h"
#  include "EPOLLWAKEUP.h"
#  include "EPOLL_CLOEXEC.h"
#  include "EPOLL_CTL_ADD.h"
#  include "EPOLL_CTL_DEL.h"
#  include "EPOLL_CTL_MOD.h"
#endif
#include "EPROTO.h"
#include "EPROTONOSUPPORT.h"
#include "EPROTOTYPE.h"
#include "ERANGE.h"
#include "EROFS.h"
#include "ESPIPE.h"
#include "ESRCH.h"
#include "ETIME.h"
#include "ETIMEDOUT.h"
#include "ETXTBSY.h"
#include "EWOULDBLOCK.h"
#include "EXDEV.h"
#include "EXIT_FAILURE.h"
#include "EXIT_SUCCESS.h"
#include "F_DUPFD.h"
#include "F_GETFD.h"
#include "F_GETFL.h"
#include "F_GETLK.h"
#include "F_SETFD.h"
#include "F_SETFL.h"
#include "F_SETLK.h"
#include "F_SETLKW.h"
#include "INT16_C.h"
#include "INT16_MAX.h"
#include "INT16_MIN.h"
#include "INT32_C.h"
#include "INT32_MAX.h"
#include "INT32_MIN.h"
#include "INT64_C.h"
#include "INT64_MAX.h"
#include "INT64_MIN.h"
#include "INT8_C.h"
#include "INT8_MAX.h"
#include "INT8_MIN.h"
#include "INTMAX_C.h"
#include "INTMAX_MAX.h"
#include "INTMAX_MIN.h"
#include "INTPTR_MAX.h"
#include "INTPTR_MIN.h"
#include "INT_FAST16_MAX.h"
#include "INT_FAST16_MIN.h"
#include "INT_FAST32_MAX.h"
#include "INT_FAST32_MIN.h"
#include "INT_FAST64_MAX.h"
#include "INT_FAST64_MIN.h"
#include "INT_FAST8_MAX.h"
#include "INT_FAST8_MIN.h"
#include "INT_LEAST16_MAX.h"
#include "INT_LEAST16_MIN.h"
#include "INT_LEAST32_MAX.h"
#include "INT_LEAST32_MIN.h"
#include "INT_LEAST64_MAX.h"
#include "INT_LEAST64_MIN.h"
#include "INT_LEAST8_MAX.h"
#include "INT_LEAST8_MIN.h"
#include "INT_MAX.h"
#include "INT_MIN.h"
#include "LLONG_MAX.h"
#include "LLONG_MIN.h"
#include "LONG_MAX.h"
#include "LONG_MIN.h"
#include "MAP_ANONYMOUS.h"
#include "MAP_PRIVATE.h"
#include "MAP_SHARED.h"
#include "MB_CUR_MAX.h"
#include "MB_LEN_MAX.h"
#include "NAME_MAX.h"
#include "NCCS.h"
#include "NULL.h"
#include "O_CLOEXEC.h"
#include "O_CREAT.h"
#include "O_DIRECTORY.h"
#include "O_RDONLY.h"
#include "O_RDWR.h"
#include "O_WRONLY.h"
#include "PATH_MAX.h"
#include "POLLERR.h"
#include "POLLHUP.h"
#include "POLLIN.h"
#include "POLLOUT.h"
#include "POLLPRI.h"
#include "PROT_EXEC.h"
#include "PROT_NONE.h"
#include "PROT_READ.h"
#include "PROT_WRITE.h"
#include "PTRDIFF_MAX.h"
#include "PTRDIFF_MIN.h"
#include "RAND_MAX.h"
#include "SCHAR_MAX.h"
#include "SCHAR_MIN.h"
#include "SHRT_MAX.h"
#include "SHRT_MIN.h"
#include "SIGABRT.h"
#include "SIGALRM.h"
#include "SIGCHLD.h"
#include "SIGFPE.h"
#include "SIGHUP.h"
#include "SIGILL.h"
#include "SIGINT.h"
#include "SIGKILL.h"
#include "SIGPIPE.h"
#include "SIGQUIT.h"
#include "SIGSEGV.h"
#include "SIGTERM.h"
#include "SIGTRAP.h"
#include "SIG_ATOMIC_MAX.h"
#include "SIG_ATOMIC_MIN.h"
#include "SIG_DFL.h"
#include "SIG_ERR.h"
#include "SIG_IGN.h"
#include "SIZE_MAX.h"
#include "STDERR_FILENO.h"
#include "STDIN_FILENO.h"
#include "STDOUT_FILENO.h"
#include "SYS_chdir.h"
#include "SYS_chmod.h"
#include "SYS_chown.h"
#include "SYS_clock_getres.h"
#include "SYS_clock_gettime.h"
#if defined(__linux__)
#  include "SYS_clock_nanosleep.h"
#endif
#include "SYS_clock_settime.h"
#if defined(__linux__)
#  include "SYS_clone.h"
#endif
#include "SYS_close.h"
#include "SYS_dup.h"
#include "SYS_dup2.h"
#if defined(__linux__)
#  include "SYS_dup3.h"
#  include "SYS_epoll_create1.h"
#  include "SYS_epoll_ctl.h"
#  include "SYS_epoll_wait.h"
#endif
#include "SYS_execve.h"
#include "SYS_exit.h"
#if defined(__linux__)
#  include "SYS_exit_group.h"
#endif
#include "SYS_fchdir.h"
#include "SYS_fcntl.h"
#include "SYS_fork.h"
#include "SYS_fstat.h"
#include "SYS_fstatat.h"
#if defined(__linux__)
#  include "SYS_get_thread_area.h"
#  include "SYS_getcwd.h"
#endif
#include "SYS_getdents.h"
#if defined(__linux__)
#  include "SYS_getdents64.h"
#endif
#include "SYS_getegid.h"
#include "SYS_geteuid.h"
#include "SYS_getgid.h"
#include "SYS_getpgid.h"
#include "SYS_getpid.h"
#include "SYS_getppid.h"
#if defined(__linux__)
#  include "SYS_gettid.h"
#endif
#include "SYS_getuid.h"
#if defined(__linux__)
#  include "SYS_inotify_add_watch.h"
#  include "SYS_inotify_init1.h"
#  include "SYS_inotify_rm_watch.h"
#endif
#include "SYS_ioctl.h"
#include "SYS_kill.h"
#include "SYS_mkdir.h"
#include "SYS_mmap.h"
#if defined(__linux__)
#  include "SYS_mremap.h"
#endif
#include "SYS_munmap.h"
#include "SYS_open.h"
#if defined(__linux__)
#  include "SYS_pause.h"
#endif
#include "SYS_pipe2.h"
#include "SYS_read.h"
#include "SYS_readlink.h"
#include "SYS_rmdir.h"
#if defined(__linux__)
#  include "SYS_set_thread_area.h"
#endif
#include "SYS_stat.h"
#include "SYS_symlink.h"
#if defined(__linux__)
#  include "SYS_tgkill.h"
#  include "SYS_uname.h"
#endif
#include "SYS_unlink.h"
#include "SYS_vfork.h"
#if defined(__linux__)
#  include "SYS_waitid.h"
#endif
#include "SYS_write.h"
#include "TCGETS.h"
#include "TCSETS.h"
#include "TCSETSF.h"
#include "TCSETSW.h"
#include "UCHAR_MAX.h"
#include "UINT16_C.h"
#include "UINT16_MAX.h"
#include "UINT32_C.h"
#include "UINT32_MAX.h"
#include "UINT64_C.h"
#include "UINT64_MAX.h"
#include "UINT8_C.h"
#include "UINT8_MAX.h"
#include "UINTMAX_C.h"
#include "UINTMAX_MAX.h"
#include "UINTPTR_MAX.h"
#include "UINT_FAST16_MAX.h"
#include "UINT_FAST32_MAX.h"
#include "UINT_FAST64_MAX.h"
#include "UINT_FAST8_MAX.h"
#include "UINT_LEAST16_MAX.h"
#include "UINT_LEAST32_MAX.h"
#include "UINT_LEAST64_MAX.h"
#include "UINT_LEAST8_MAX.h"
#include "UINT_MAX.h"
#include "ULLONG_MAX.h"
#include "ULONG_MAX.h"
#include "USHRT_MAX.h"
#include "WCHAR_MAX.h"
#include "WCHAR_MIN.h"
#include "WCONTINUED.h"
#include "WEXITED.h"
#include "WINT_MAX.h"
#include "WINT_MIN.h"
#include "WNOHANG.h"
#include "WNOWAIT.h"
#include "WSTOPPED.h"
#include "WUNTRACED.h"
#include "abs.h"
#include "alloca.h"
#include "auxv_t.h"
#include "blkcnt_t.h"
#include "blksize_t.h"
#include "cc_t.h"
#include "char16_t.h"
#include "char32_t.h"
#include "clock_t.h"
#include "clockid_t.h"
#include "dev_t.h"
#include "div_t.h"
#if defined(__linux__)
#  include "epoll_data_t.h"
#endif
#if defined(__FreeBSD__)
#  include "fflags_t.h"
#endif
#include "gid_t.h"
#include "id_t.h"
#include "idtype_t.h"
#include "ino_t.h"
#include "int16_t.h"
#include "int32_t.h"
#include "int64_t.h"
#include "int8_t.h"
#include "int_fast16_t.h"
#include "int_fast32_t.h"
#include "int_fast64_t.h"
#include "int_fast8_t.h"
#include "int_least16_t.h"
#include "int_least32_t.h"
#include "int_least64_t.h"
#include "int_least8_t.h"
#include "intmax_t.h"
#include "intptr_t.h"
#include "ldiv_t.h"
#include "lldiv_t.h"
#include "memcmp.h"
#include "memcpy.h"
#include "memset.h"
#include "mode_t.h"
#include "nlink_t.h"
#include "off_t.h"
#include "offsetof.h"
#include "pid_t.h"
#include "ptrdiff_t.h"
#include "siginfo_t.h"
#include "size_t.h"
#include "speed_t.h"
#include "ssize_t.h"
#include "strcmp.h"
#include "strlen.h"
#if defined(__linux__)
#  include "struct epoll_event.h"
#  include "struct linux_dirent.h"
#endif
#include "struct pt_regs.h"
#include "struct rusage.h"
#include "struct stat.h"
#include "struct termios.h"
#include "struct timespec.h"
#include "struct timeval.h"
#if defined(__linux__)
#  include "struct user_desc.h"
#endif
#include "struct utsname.h"
#include "suseconds_t.h"
#include "tcflag_t.h"
#include "time_t.h"
#include "timer_t.h"
#include "uid_t.h"
#include "uint16_t.h"
#include "uint32_t.h"
#include "uint64_t.h"
#include "uint8_t.h"
#include "uint_fast16_t.h"
#include "uint_fast32_t.h"
#include "uint_fast64_t.h"
#include "uint_fast8_t.h"
#include "uint_least16_t.h"
#include "uint_least32_t.h"
#include "uint_least64_t.h"
#include "uint_least8_t.h"
#include "uintmax_t.h"
#include "uintptr_t.h"
#include "union sigval.h"
#include "va_arg.h"
#include "va_copy.h"
#include "va_end.h"
#include "va_list.h"
#include "va_start.h"
#include "wchar_t.h"
#include "wint_t.h"
