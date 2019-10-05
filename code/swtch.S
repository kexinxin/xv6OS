# Context switch
#
#   void swtch(struct context **old, struct context *new);
# 
# Save the current registers on the stack, creating
# a struct context, and save its address in *old.
# Switch stacks to new and pop previously-saved registers.

.globl swtch
swtch:
  movl 4(%esp), %eax #把old放到eax中
  movl 8(%esp), %edx #把new放到edx中

  #已经隐式的保存eip,函数调用时压入
  # Save old callee-save registers
  pushl %ebp
  pushl %ebx
  pushl %esi
  pushl %edi
  #此时栈结构就是一个'struct context'

  # Switch stacks
  movl %esp, (%eax)#把esp保存到old指向的地址,esp直接作为context的地址被保存
  movl %edx, %esp  #切换到new指向的地址

  # Load new callee-save registers
  popl %edi
  popl %esi
  popl %ebx
  popl %ebp
  #还有一个eip未弹出，刚好由ret弹出
  ret
