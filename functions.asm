global timestamp
timestamp:
    RDTSC
    ret
extern xchng_cnt
global xchng
xchng:
    push ebp
    mov ebp, esp
    push ebx
    inc dword[xchng_cnt]
    mov edx, dword [ebp+8] 
    mov ecx, dword [ebp+12] 
    mov ebx, dword [edx] 
    mov eax, dword [ecx] 
    mov dword [edx], eax 
    mov dword [ecx], ebx 
    pop ebx
    mov esp, ebp
    pop ebp
    xor eax, eax
    ret
extern cmp_cnt
global compare
compare:
    push ebp
    mov ebp, esp
    mov esp, ebp
    inc dword[cmp_cnt]
    mov ebx, dword[ebp+8]
    cmp ebx, dword[ebp+12]
    jl  .less
    mov eax, 0
    jmp .end
.less:
    mov eax, 1
.end:
    mov esp, ebp
    pop ebp
    ret