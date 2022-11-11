// array 
let names: string[] = ["Tobi", "Albertino"]
let numbers: Array<number> = [1, 2, 3]

// change value array 
names[0] = "Khoiru"

// tuple
let student: [string, string, number] = ["1001", "Tobi", 99]
let product: [string, number] = ["Mouse", 999]

product[1] = 1000000

console.log(names[0])
console.log(names[1])

console.log(student[0])
console.log(product[1])

let names2: string[] = []
names2.push("Tobi")
names2.push("Albertino")
names2.push("---")

// delete array 
delete names2[2]

console.log(names2)