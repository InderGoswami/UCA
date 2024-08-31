//promises are type of object implemented using constructor function
//Name of constructor function
// function promiseExecutor(){
//     setTimeout(()=>{
//         console.log("Promise execution")
//     },10000);//async
// }
// var promise1=new Promise(promiseExecutor);//create simple promise
// //promise will execute Promise constructor function qhich itself will call promiseExecutor function
// var promise2=new Promise();
//promise is an object used by creating constructor function and have 2 properties state and value
//State of promises have 3 values:-1.Pending 2.fullfill 3.rejected
//Link this concept with https request if data is succesfully fetched we can say promise is fullfill state and if 
//data is not fetched we can say data is rejected
//value:- Possible value dependant on state
//2 Values are possible
//if state is pending , value is undefined
//if state is rejected ,error will be value
//if state is fullfilled,value will be actual value
//promise1===promise2;->false
//Promise requires function as argument
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//client to server type promise
function promiseExecutor(resolve,reject) {//promiseExecutor function can have 2 arguments
    setTimeout(() => {
        resolve({response:"responseValue"});
        //reject({response:"responseValue"});
        console.log("Promise execution")
    }, 1000);//async
}

var promise1=new Promise(promiseExecutor);//create simple promise
//A promise is resolved or rejected when any one argument of promiseExecutor will be used
//Now promise1 will have fullfilled state
//then and catch functions are chaining function used to get value of resolve and reject
//then function also accepts callback having value as argument which will be storing value returned by reject and resolve methods
//then and cath are method of contuctor function Promise
let responseErrorValue;
promise1.then((valu)=>{//then corresponding resolve
    responseErrorValue=valu;
    console.log("Fulfilled with:", value); /
});
promise1.catch((valu)=>{//catch corresponding reject
    responseValue=valu;
    console.log("Rejected with:", error); 
});
