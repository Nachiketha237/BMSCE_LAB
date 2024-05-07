// Create a database “Student” with the following attributes Rollno, Age, ContactNo, Email-Id.
db.createCollection("Student");

// Insert appropriate values
db.Student.insertMany([{ Rollno: 1, Age: 20, ContactNo: 9743349334, Email: "123@gmail.com" }, { Rollno: 2, Age: 19, ContactNo: 787873264, Email: "gyan@gmail.com" }, { Rollno: 3, Age: 21, ContactNo: 684563243, Email: "baz@gmail.com" }, { Rollno: 4, Name: "Sam", Age: 20, ContactNo: 9372347623, Email: "sam@gmail.com" }, { Rollno: 5, Age: 19, ContactNo: 9679346643, Email: "don@gmail.com" }]);

db.Student.find();

// Write query to update Email-Id of a student with rollno 1.

db.Student.update({ Rollno: 1 }, { $set: { Email: "ravi@gmail.com" } });
db.Student.find({ Rollno: 1 });

// Replace the student name from “Sam” to “Ram” of rollno 4
db.Student.update({ Rollno: 4 }, { $set: { Name: "Ram" } });
db.Student.find({ Rollno: 4 });

//Display Student Name and grade(Add if grade is not present)where the Rollno is 4.
db.Student.find({Rollno:4},{Name:1,Grade:1});

// Update to add hobbies
db.Student.update({Rollno:3},{$set:{Hobbies:['Cricket','Anime']}});


// Find documents where hobbies is set neither to Chess nor to Skating
db.Student.find({Hobbies:{$nin:['Chess','Skating']}});

// 8.Find documents whose name begins with R
db.Student.find({Name:/^R/});
