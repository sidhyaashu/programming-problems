// 'ts-node'

let firstName:string="Asutosh sidhya";
let lastName = "Sidhya";
let v:any = "Sidhya";
v=5;


let w:unknown = 1;
w ="Suidhay";
w={
    runANonExistingMethod :()=>{
        console.log("object")
    }
} as {
    runANonExistingMethod:()=>void;
}

const json = JSON.parse("55");
console.log(typeof json);
