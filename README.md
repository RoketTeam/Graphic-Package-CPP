

#  Graphic-Package-CPP

Graphic Package is a static library for programmers, which allow to set I / O patterns in a Windows console environment using a collection of controls.

# Code Style


We used Google C++ Style Guide.

## Demo

#### CheckList
<img width="203" alt="checklist" src="https://user-images.githubusercontent.com/34625584/43034212-248262d0-8ce1-11e8-8050-0dc9c0eca881.png">

##### How to use - Code example

###### Create en empty Checklist (Constructor gets nothing)
CheckList checkList;                       

###### Add some list items
checkList.add_selected_item(new ListItem("Black"));                 
checkList.add_selected_item(new ListItem("Espresso"));
checkList.add_selected_item(new ListItem("Espresso with milk"));
checkList.add_selected_item(new ListItem("Americano"));

###### Set margin (margin from bottom or margin from left)
checkList.set_margin(3);                                            
checkList.set_margin_left(5);                                       

#### ComboBox

<img width="297" alt="combobox1" src="https://user-images.githubusercontent.com/34625584/43034223-57a8bf7e-8ce1-11e8-9bfb-60440c13d6db.png">

<img width="287" alt="combobox" src="https://user-images.githubusercontent.com/34625584/43034221-42429ae2-8ce1-11e8-9d88-5b4c07b3c05a.png">

##### How to use - Code example (similar to Checklist)

ComboBox comboBox;                                      
comboBox.add_selected_item(new ListItem("Elite"));
comboBox.add_selected_item(new ListItem("Jacobs"));
comboBox.add_selected_item(new ListItem("TesterChoice"));
comboBox.set_margin(3);


#### MessageBox

<img width="216" alt="messagebox" src="https://user-images.githubusercontent.com/34625584/43034226-6ce58ae8-8ce1-11e8-839a-0a82bcda8180.png">

##### How to use - Code example 

MyMessageBox messageBox(string: message);  
messageBox.set_ok_text("Submit");           
messageBox.set_cancel_text("cancel");       

#### NumericBox
<img width="73" alt="numericbox" src="https://user-images.githubusercontent.com/34625584/43034238-9da36d9e-8ce1-11e8-8ce6-7bda201f94fb.png">

##### How to use - Code example 

NumericBox numericBox(int: min_value, int: max_value);
NumericBox numericBox();                                
numericBox.inc()                                        
numericBox.dec()                                        


#### Panel - Form example

<img width="368" alt="panel" src="https://trello-attachments.s3.amazonaws.com/5aec85de7ae4cd018396e831/5b0c31a824407fcd406a38ac/e6ab102ad9fc343904f4a7b1b1e2b38d/Screen_Shot_2018-07-13_at_20.49.22.png">

#### Panel - Form conclusions example

<img width="368" alt="panel-answer" src="https://trello-attachments.s3.amazonaws.com/5aec85de7ae4cd018396e831/5b0c31a824407fcd406a38ac/360690e493bc93656a805c01cd982a59/Screen_Shot_2018-07-13_at_20.45.57.png">
