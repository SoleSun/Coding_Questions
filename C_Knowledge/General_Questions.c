//What is a page fault? A seg fault?
Segmentation fault indicates that a program attempted to access an invalid or illegal memory
address. This is equivalent to the HARD_FAULT or DATA_ABORT exception handling in ARM micro-
controlers. 

Page faults indicates that when a pointer tries to access a page of address space that's 
currently not mapped onto physical memory, so that the MMU needs to grab it off of disk 
before it can be used. 

// How does virtual memory work?
It is a storage allocation scheme in which secondary memory can be addressed as though it
were part of main memory. The addresses a program may use to reference memory are distinguished
from the addresses the memory system uses to identify physical storage sites, and program 
generated addresses are translated automatically to the corresponsind machine addresses. 
