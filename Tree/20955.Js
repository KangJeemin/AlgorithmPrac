const readLine = require('readline');

const rl = readLine.createInterface({
    input:process.stdin,
    output:process.stdout,
});

const input =[];

rl.on("line",(line)=>{
    input.push(line.trim());
}).on("close",()=>{
    const [N,M] = input[0].split(" ").map(Number);
    const parent = Array(N+1).fill(0).map((_,idx)=>idx); // 자기 자신으로 초기화

    // union-find
    const find = (node) => {
        if(parent[node]===node) return node;
        parent[node] = find(parent[node]);
        return parent[node];
    }

    const unionset = (a,b) => {
        let pa = find(a);
        let pb = find(b);

        if(pa===pb) return false; // 사이클 발견

        if(pa>pb){
            parent[pb]=pa;
        }
        else{
            parent[pa]=pb;
        }

        return true;
    }

    let cutcount =0;

    for(let i=1;i<=M;i++){
        const [a,b] = input[i].split(" ").map(Number);
        if(!unionset(a,b)){
            cutcount++;
        }
    }

    // 연결 요소 개수 세기
    let components = 0;
    for(let i=1;i<=N;i++){
        if(find(i)===i)
        components++;
    }

    const add = components -1;
    console.log(add + cutcount);
});