### What is the difference between shallow and deep copy?
* Shallow copy is where only the contents are copied to the new values and it points to the same location.
* When this happens if we modify the new contents, old contents can also get modified.
* Usually default copy constructor does shallow copy.
* Deep copy is where space is dynamically allocated and data is copied to the new memory location.
* To make copy constructor work as deep copy we need to write a custom copy constructor.
### static keyword
* When a variable is declared static , space for it gets allocated for life time of the program. Even if is called multiple times space for it gets allocated only once and value of variable is used from previous ones.