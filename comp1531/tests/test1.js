// veriable definition
// for loop
let k = [1, 2, 3]
for (let i in k)
{
    console.log(i);
}

// dicts are also objects
let j = {a: 1, b:2, c:3};
console.log(j);
console.log(j.a);

let  jk = [
    {
        a:1,
        b:2,
    },
    {
        y:3,
        z:4,
    }
]


console.log(jk.length);
console.log(jk.entries);

for (const key in jk)
{
    console.log(`${key} -> \n`);
}

let students = [
    {
        name: "abc",
        score: 22,
    }, 
    {
        name: "def",
        score: 48,
    },
    {
        name:"ghi",
        score: 99,
    }
]

for (const student in students)
{
    console.log(`${student.name} got ${student.score}`);
}
