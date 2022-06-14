# C_Learning

This repository contains the source code for the C_Learning project.

This project allow to follow my learning progress in C language.

## Dependencies

In order to use this project, you need to have libmysql client installed.

You can find the ZIP archive for Windows [here](https://downloads.mysql.com/archives/c-c/).

After extracting the archive, you have to add, in your CMakeLists.txt file, the following line:

With the others "SET" lines.
```
set(FULL_PATH_TO_MYSQL_CONNECTOR_C_DIR "Your path to the MySQL Connector C extracted folder")
```

After the "ADD_EXECUTABLE" line, you have to add the following lines:
```
target_link_libraries(Starting_C ${FULL_PATH_TO_MYSQL_CONNECTOR_C_DIR}/lib/libmysql.lib)
include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_C_DIR}/include)
include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_C_DIR}/include/mysql)
link_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_C_DIR}/lib)
```

## Usage

You can find differents functions, such as:
* **getHours**: calculate the number of hours from a number of minutes
* **BMI**: calculate the BMI of a person
* **IntToString**: convert an integer to a string
* **UnitConverter**: convert a number of unit to another unit
* **ContactManager**: manage a list of contacts
* **DBManager**: manage a database

## Possible errors

If you can't launch your code or if you can't connect to the database, you have to copy the libmysql.dll file in the same folder as the executable.

This file is located in the lib folder of the MySQL Connector C.

