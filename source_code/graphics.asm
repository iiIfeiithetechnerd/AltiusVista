section .text
    global _start

_start:
    ; write system call
    mov edx, len        ; message length
    mov ecx, msg        ; message to write
    mov ebx, 1          ; file descriptor (stdout)
    mov eax, 4          ; system call number (sys_write)
    int 0x80            ; invoke kernel

    ; exit system call
    mov eax, 1          ; system call number (sys_exit)
    int 0x80            ; invoke kernel

section .data
    msg db 'Initiating graphics runtime...', 0xa
    len equ $ - msg   