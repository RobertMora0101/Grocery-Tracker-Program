Grocery Tracker Program

Project Summary
The Grocery Tracker Program is designed to read a list of grocery items from a file, count their occurrences, and provide useful insights to the user. It allows users to search for a specific item, display all items with their purchase frequencies, and generate a visual histogram of purchases. The program ensures that data is saved in a separate file for future reference.

What I Did Well
I implemented efficient data handling by reading grocery items from a file and counting occurrences using a data structure that optimizes lookups. Additionally, I ensured user-friendly interaction by designing a clear and structured menu system, making it easy for users to access data. Error handling was another strength, as the program checks for file access errors and invalid inputs to ensure a smooth user experience.

Areas for Improvement
While the program functions correctly, there are areas where I could enhance its efficiency and security:

•	Optimize Data Storage: Using an unordered_map instead of a regular map would improve performance for frequent lookups.

•	Expand Input Handling: Allowing users to add new items dynamically instead of only reading from a file would increase flexibility.

•	Improve Error Handling: Adding exception handling (try-catch blocks) for file operations and user input validation would make the program more robust.

Challenges and Solutions
One of the biggest challenges was parsing and normalizing data from the input file while ensuring case consistency. Initially, I struggled with distinguishing uppercase and lowercase versions of the same item. To solve this, I implemented a function to convert all inputs to lowercase before processing. Additionally, handling file errors was tricky, so I added checks to verify if the file exists and is accessible before attempting to read data.

Transferable Skills
This project helped me develop key programming skills that will be useful in future coursework and professional settings:

•	File Handling in C++: Essential for managing external data sources efficiently.

•	Data Structures (Maps & Vectors): Useful for organizing and retrieving data quickly.

•	User Input Validation: A critical skill for writing secure programs that handle unexpected inputs gracefully.

Code Maintainability and Readability
To ensure the program remains maintainable and readable, I followed best practices:

•	Clear Function Names: Each function was named descriptively to indicate its purpose.

•	Modular Code Structure: The program is divided into distinct functions to keep logic organized.

•	Inline Comments: Key sections of the code are explained with comments to aid future modifications.

•	Consistent Formatting: Proper indentation and spacing improve readability.
