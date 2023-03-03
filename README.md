# MySTL

### This repo will accomplish some Simple STL Container, Algorithm and Iterator， Fuction object
[Reference](https://blog.csdn.net/TowerOs/article/details/103957395)
![image](Image/20200113145457969.png)
![image](Image/20200113170635707.png)

#### Container
#### Vector
</br>![image](Image\vector.png)<br/>
* 3/1/2023
- [x] construct function of the vector
- [x] deconstruct function of the vector
- [x] copy construct function of the vector
- [x] member function: push_back
<br/> the improvement of the push_back: </br>
Cumulative increase time complexity O(n) 
<br/>![image](Image/Cumulative_increase.png)</br>
<br/> Multiply increase time complexity O(1)</br>
<br/> ![image](Image/multiply.png) </br>
<br/> **my imporvemnet:** <br/>
<br/>the origin way to expansion is toExpanding the capacity by 2 times will cause the memory requested next time to be greater than the sum of the previously allocated memory, causing the previously allocated memory to no longer be used, so it is best to set the doubling growth factor between (1,2).
 I seted the 1.5 times of vector in my poject.<br/>

*  3/2/2023
- [x] test push_back the result and capacity as below it works :grin:
<br/>![image](Image/test_push_bcak.png)</br>
<br/>![image](Image/result_push_back.png)</br>
***
###### small issue:
Overflow Stack:
when i set the 1.5 times to expend the capacity, the Overflow stack happend, I think when I push the one new character it did not expand the enough stack memory for the new item, so I change the 2 times memory for using.
***
**Member Function**
- [x] pop_back()
- [x] size()
- [x] capacity() 
- [x] front() 
- [x] end()
- [x] insert(iterator *it, value), 
- [x] erase(iterator *it)
- [x] back()
***
###### improve space:
Without getting rid of the dependence on std, the iterator still relies on std, and the algorithm still relies on the stl "algorithm" library, the plan of
further work:
1. continue the container including <string, map, under_ordered_map, maybe create a new container "Tree" :black_nib:>
2. finish the basic algorithm including <sort, compare etc> 
3. create document and measure structure
***



#### String
</br>![image](Image\string.png)<br/>
3/3/2023
- [x] construct
- [x] destruct
- [x] copy constrcut
- [x] size()
- [x] length()
- [x] max_size()

