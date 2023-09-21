section .data
    format db "Hello, Holberton",10,0 ; The format string with a newline character

section .text
    global main

extern printf
main:
    push rbp                ; Save the base pointer
    mov rdi, format         ; Load the format string address into rdi
    call printf            ; Call printf function
    pop rbp                 ; Restore the base pointer

    ; Exit the program
    mov rax, 60             ; syscall: exit
    xor rdi, rdi            ; status: 0
    syscall
