const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
})

const input = [];

rl.on("line",(line)=>{
    input.push(line.trim());
}).on("close",()=>{
    let [N,M] = input[0].split(' ').map(Number);
    let map = input.slice(1).map(line=>line.split('').map(Number));
    let visited = Array.from({ length:N }, ()=>Array(M).fill(false));
    let direciton =[
        [0,1],[0,-1],[1,0],[-1,0]
    ];
    
    let queue = [];
    queue.push([0,0,1]);
    visited[0][0]=true;

    while(queue.length){
        const [x,y,count] = queue.shift();
        if(x===N-1 && y===M-1){
            console.log(count);
            break;
        }

        for(let i=0;i<4;i++){
            const nx = x + direciton[i][0];
            const ny = y + direciton[i][1];
            if( 0 <= nx && nx < N && 0<= ny && ny < M){
                if(!visited[nx][ny] && map[nx][ny]===1){
                    visited[nx][ny]=true;
                    queue.push([nx,ny,count+1]);
                }
            }
        }
    

    }
});