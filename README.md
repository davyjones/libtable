libtable
========

A library to output data in tabular form.

Class layout and methods
------------------------

* ```Table``` classes for creating tables. Tables are created but not displayed. Use ```Table.show()``` to display the table.
* ```setData(QStringList)``` for replacing data of a table without changing its size. 
* ```appendData(QStringList)``` for adding data to a table that would also change its size accordingly. Spaces in the string list are converted to line breaks. The longest string list subgroup without a line break will be the width of the table.
* ```horizontalHeadersOn/Off()``` to turn on/off horizontal headers. Default is on.
* ```verticalHeadersOn/Off()``` to turn on/off vertical headers. Default is on.

Build instructions
------------------

Qt ecosystem is not necessary but preferred. Definitely need atleast qmake and Qt libraries to build this library.

Works on version 4.8.2.

Usage
-----

Create your class from the Table class. Make sure to point to the right headers and libraries.
