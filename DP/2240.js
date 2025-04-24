// 매 초마다, 두 개의 나무 중 하나의 나무에서 열매가 떨어지게 된다. 만약 열매가 떨어지는 순간, 자두가 그 나무의 아래에 서 있으면 자두는 그 열매를 받아먹을 수 있다.
// 두 개의 나무는 그다지 멀리 떨어져 있지 않기 때문에, 자두는 하나의 나무 아래에 서 있다가 다른 나무 아래로 빠르게(1초보다 훨씬 짧은 시간에) 움직일 수 있다.
// 하지만 자두는 체력이 그다지 좋지 못해서 많이 움직일 수는 없다.
// 자두는 T(1≤T≤1,000)초 동안 떨어지게 된다. 자두는 최대 W(1≤W≤30)번만 움직이고 싶어 한다. 매 초마다 어느 나무에서 자두가 떨어질지에 대한 정보가 주어졌을 때, 
// 자두가 받을 수 있는 자두의 개수를 구해내는 프로그램을 작성하시오. 자두는 1번 자두나무 아래에 위치해 있다고 한다.

const readline = require('readline');

const rl = readline.createInterface({
    input:process.stdin,
    output:process.stdout
});

const input = [];

rl.on('line',(line)=>{
    input.push(line.trim());
}).on('close',()=>{
    const [T,W] = input[0].split(' ').map(Number);
    const Tree = input.slice(1).map(Number);
    //시간, 자두의 위치, 총이동횟수 
    const dp = Array.from( {length:T},()=> Array.from( {length:3},()=>Array(W+1).fill(0)));

    // 초기작업
    if(Tree[0]==1){
        dp[0][1][0] = 1;
        dp[0][2][1] = 0;
    }
    else{
        dp[0][1][0] = 0;
        dp[0][2][1] = 1;
    }
    

    for(let t=1;t<T;t++){
        const treeNum = Tree[t];

        // 이걸 생각 못했네.
        for(let w=0;w<=W;w++){
            if(treeNum===1){
                dp[t][1][w] = Math.max(dp[t-1][1][w]+1, w>0 ? dp[t-1][2][w-1] + 1 :0);
                dp[t][2][w] = Math.max(dp[t-1][2][w], w>0 ? dp[t-1][1][w-1] :0);
            }
            else{
                dp[t][2][w] = Math.max(dp[t-1][2][w]+1, w>0 ? dp[t-1][1][w-1]+1 :0);
                dp[t][1][w] = Math.max(dp[t-1][1][w], w>0 ? dp[t-1][1][w-1]:0);
            }
        }
    }

    let maxAns =0;
    for(let w=0;w<=W;w++){
        maxAns = Math.max(maxAns,dp[T-1][1][w],dp[T-1][2][w],maxAns);
    }
    console.log(maxAns);

})


//T, 자두의 위치, 이동횟수 
// [1][1][0] = 0
// [1][2][1] = 2

// [2][1][0] = 0 + 1; => [1][1][0] + 1
// [2][2][1] = 2 + 0; => [1][2][1] + 0
// [2][1][2] = 2 + 1  => [1][2][1] + 1;

// [3][1][0] = 0 + 1 + 1; => [2][1][0] +1;

// [3][2][1] = 0 + 1 + 0; => [2][1][0] + 0;
// [3][2][1] = 2 + 0 + 0  => [2][2][1] + 0

// [3][1][2] = 2 + 1 + 1 => [2][1][2] + 1 
