const readLine = require('readline');
const rl = readLine.createInterface({
    input:process.stdin,
    output:process.stdout,
});

const input=[];

class PrioiryQueue{
    constructor(){
        this.queue=[];
    }
    print(){
        if(this.queue.length===0){
            console.log(0);
            return;
        }else{
            console.log(this.queue[0]);
            this.queue.shift();
        }
    }
    push(num){
        for(let i=0;i<this.queue.length;i++){
            if(this.queue[i]<=num){
               this.queue.splice(i,0,num);
               return;
            
            }
        }
        this.queue.push(num);

    }


}

rl.on("line",(line)=>{
    input.push(line.trim());
}).on("close",()=>{
    const N = +input[0];
    const prioiryQueue = new PrioiryQueue();
    for(let i=1;i<=N;i++){
        const num = input[i];
        if(num==0){
            prioiryQueue.print();
        }
        else{
            prioiryQueue.push(num);
        }
    }
    
})