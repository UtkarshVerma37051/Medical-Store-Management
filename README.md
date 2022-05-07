# Medical-Store-Management

## Introduction :
This is a medical store management project written in C++.
It deals with storing the details of the `customers`, `supplier`, `inventory` , along with managing the inventory/stock. (<font color="blue">Admin only</font>).
## It consists of 2 sections :

### 1. Admin
This is a **password protected** section. In this section, Admin can :
1. `add/list` the details of the supplier , view purchase history of supplier.
2. View customer's record and there purchase history.
3. Manage inventory by `adding` , `deleting` , `searching` , `viewing` and `modifying` the details of medicine.
4. Reset login password (Initial password : `sedawk`)

### 2. Customer
1. `Add/remove` medicines to cart.
2. View cart.
3. `Generate bill` for the purchased item.
- - -

## Build and run using Make

There is a makefile present in the root of repository which can be used to build and run the project.

`make all` : builds and runs the project.



<details>
<summary>Other make targets</summary>
<br>

`make clean` : cleans the build directory.
`make compile` : compiles the sources files to object files (`build/*.o`).
`make link`    : links the object files and create the executable <font color="green">medical.exe</font> which is present in <font color="green" >build/bin</font> directory (if not specified).
`make run`     : runs the exe (if already built).
</details>

##### Pending tasks
- [ ] Add the suppport of CMake for the project.

---
###Support

:e-mail: : utkarsh.verma.37051@gmail.com
