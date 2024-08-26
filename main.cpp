#include <iostream>
#include <new>

class Object {
public:
    int data;
    Object();
};
Object::Object()
{
    data = 10;
}
void explicit_constructor_call(Object* ptr)
{
    new (ptr) Object(); 
}
int main()
{
    label1:
    void* memory = operator new(sizeof(Object));  // Allocate a memory block for the object.
    Object* ptr  = static_cast<Object*>(memory);  // Cast the memory block to the object type.
    //ptr->Object::Object();                        // Calling the constructor is not allowed by the compiler.
    explicit_constructor_call(ptr);               // Call the constructor explicitly using placement new.                            
    std::cout<< ptr->data;
    return 0;
}
