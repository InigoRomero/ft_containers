# ft_containers
<br/>
<b>  Reimplementing C++ Containers, for study purposes :)  
<br/>

## VECTOR ✅
#### Member functions
- [x] Constructor	
- [x] Destructor
- [x] operator=

#### Iterators:
- [x] begin	
- [x] end
- [x] rbegin	
- [x] rend	
- [x] cbegin	
- [x] cend	
- [x] crbegin	
- [x] crend	

#### Capacity:
- [x] size	
- [x] max_size	
- [x] resize	
- [x] capacity	
- [x] empty	
- [x] reserve	
- [x] shrink_to_fit	

#### Element access:
- [x] operator[]	
- [x] at	
- [x] front	
- [x] back	
- [x] data	

#### Modifiers:
- [x] assign	
- [x] push_back	
- [x] pop_back	
- [x] insert	
- [x] erase	
- [x] swap	
- [x] clear	
- [x] emplace	
- [x] emplace_back	

#### Allocator:
- [x] get_allocator	

#### Non-member function overloads
- [x] relational operators	
- [x] swap


## STACK ✅

#### Member functions
- [x] Constructor
- [x] empty	
- [x] size	
- [x] top
- [x] push	
- [x] pop	
- [x] swap	

#### Non-member function overloads
- [x] relational operators	
- [x] swap (stack)	

#### Non-member class specializations
- [x] uses_allocator<stack>

## MAP ⌛
#### Member functions
- [x] Constructor	
- [ ] Destructor
- [x] operator= //  Operator[] , see how to insert with = after returning this value

#### Iterators:
- [x] begin	
- [x] end
- [x] rbegin	
- [x] rend	
- [x] cbegin	
- [x] cend	
- [ ] crbegin	
- [ ] crend	

#### Capacity:
- [x] size	
- [x] max_size	
- [x] empty	


#### Element access:
- [x] operator[]	
- [ ] at

#### Modifiers:
- [x] insert
    - [ ] Return last value inserted
	- [ ] Why inserting with [] is skipping numbers ?
- [ ] erase	//Mising erase for Position
- [ ] swap	
- [x] clear	
- [ ] emplace	
- [ ] emplace_hint

#### Observers:
- [x] key_comp	
- [x] value_comp

#### Operations:
- [x] find	
- [x] count
- [ ] lower_bound	
- [ ] upper_bound	
- [ ] equal_range	

#### Allocator:
- [ ] get_allocator
