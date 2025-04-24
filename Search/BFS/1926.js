const readLine = require('readline');
const rl = readLine.createInterface({
    input:process.stdin,
    output:process.stdout,
});

const input = [];
rl.on("line",(line)=>{
    input.push(line.trim());
}).on("close",()=>{
    const [N,M]= input[0].split(' ').map(Number);
    const paper = input.slice(1).map(line=> line.split(' ').map(Number));
    const visited = Array.from({ length: N} ,()=> Array(M).fill(false));

    const direciton =[
        [0,1],[0,-1],[1,0],[-1,0]
    ];

    let count = 0;
    let area = 0;
    
    function BFS(startX, startY){
        let queue = [[startX,startY,1]];
        visited[startX][startY]=true;

        let Area = 1;
        while(queue.length){
            const [X,Y] = queue.shift();

            if(Area > area){
                area = Area;
            }


            for(let i=0;i<4;i++){
                let NX = X + direciton[i][0];
                let NY = Y + direciton[i][1];

                if (
                    NX >= 0 && NX < N &&
                    NY >= 0 && NY < M &&
                    !visited[NX][NY] && paper[NX][NY] === 1
                  ){
                    visited[NX][NY]=true;
                    queue.push([NX,NY]);
                    Area++;
                }
            }
        }

        if(Area > area){
            area = Area;
        }
    }

    for(let i=0;i<N;i++){
        for(let j=0;j<M;j++){
            if(!visited[i][j] && paper[i][j]===1){
                count++;
                BFS(i,j);
            }
        }   
    }
    console.log(count);
    console.log(area);
    
})