# android_reverseShell


On server side run:
netcat -nlvp 1337

Compilation:
------------

gcc -Wall -o shell tcp_reverse_shell.c

$NDK_HOME/toolchains/llvm/prebuilt/linux-x86_64/bin/armv7a-linux-androideabi23-clang -Wall -o tcp_rev_shell_android_23 tcp_reverse_shell.c
