// Create a collection by name Customers
db.createCollection("Customers");

// Insert at least 5 values into the table
sample_customers = [
    {
        "Cust_id": 101,
        "Acc_Bal": 10800,
        "Acc_Type": "Savings"
    },
    {
        "Cust_id": 102,
        "Acc_Bal": 53000,
        "Acc_Type": "Current"
    },
    {
        "Cust_id": 103,
        "Acc_Bal": 22000,
        "Acc_Type": "Savings"
    },
    {
        "Cust_id": 104,
        "Acc_Bal": 50000,
        "Acc_Type": "Business"
    },
    {
        "Cust_id": 105,
        "Acc_Bal": 25000,
        "Acc_Type": "Savings"
    }
]
db.Customers.insertMany(sample_customers);

// Write a query to display those records whose total account balance is greater than 50000 of account type ‘Current’ for each customer_id.

db.Customers.find({ Acc_Type:"Current",Acc_Bal:{$gte:50000}});

// Determine Minimum and Maximum account balance for each customer_i

db.Customers.aggregate([
    {
        $group: {
            _id: "$Cust_id",
            minBalance: { $min: "$Acc_Bal" },
            maxBalance: { $max: "$Acc_Bal" }
        }
    }
]);
// Sort the documents based on Customer ID in ascending order and Account Balance in descending
// order
db.Customers.find().sort({Cust_id:1});
db.Customers.find().sort({Acc_Bal:-1});
  
// Display only 2 nd and 3 rd records from the collection
db.Customers.find().skip(1).limit(2);
