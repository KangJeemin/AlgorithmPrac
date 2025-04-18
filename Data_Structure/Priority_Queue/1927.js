const readLine = require('readline');
const rl = readLine.createInterface({
    input:process.stdin,
    output:process.stdout,
});

const input=[];

class MinHeap{
    constructor(){
        this.queue=[null];
    }
    print(){
        if(this.queue.length===1)
            return 0;
        if(this.queue.length===2){
            return this.queue.pop();
        }
            const minV = this.queue[1];
            // heap에서 최솟값을 뺴고 난 후 ,재구조화
            this.queue[1] = this.queue.pop();
            let idx = 1;
            while(true){
                let left = idx * 2;
                let right= idx * 2 +1;
                let smallest = idx;

                if(left < this.queue.length && this.queue[left] < this.queue[smallest]){
                    smallest = left;
                }

                if(right < this.queue.length && this.queue[right] < this.queue[smallest]){
                    smallest = right;
                }

                // 탐색 종료
                if(smallest === idx) break;
                [this.queue[idx],this.queue[smallest]] = [this.queue[smallest],this.queue[idx]];
                idx = smallest;
            }
            return minV;
    }
    push(num){
        this.queue.push(num);
        let idx = this.queue.length - 1;
        while (idx > 1 && this.queue[Math.floor(idx / 2)] > this.queue[idx]) {
            [this.queue[Math.floor(idx / 2)], this.queue[idx]] = [this.queue[idx], this.queue[Math.floor(idx / 2)]];
            idx = Math.floor(idx / 2);
        }
    }

}

rl.on("line",(line)=>{
    input.push(line.trim());
}).on("close",()=>{
    const N = +input[0];
    const prioiryQueue = new MinHeap();

    let output = [];
    for(let i=1;i<=N;i++){
        const num = +input[i];
        
        if(num==0){
            output.push(prioiryQueue.print());
            // console.log(prioiryQueue.print()); 시간초과 발생
        }
        else{
            prioiryQueue.push(num);
        }
    }
    console.log(output.join('\n'));
    //

})