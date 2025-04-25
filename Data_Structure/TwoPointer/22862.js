const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

const input =[];
rl.on('line',(line)=>{
    input.push(line.trim());
}).on('close',()=>{
    const [N,K] = input[0].split(' ').map(Number);
    const inputArray = input[1].split(' ').map(Number);

    let start = 0;
    let end =0;
    let odd =0;
    let longest = 0;


    while(end < N){
        // 홀수인경우
        if(inputArray[end] % 2 ===1){
            odd++;
        }
        // 홀수를 초과한 경우 슬라이딩 윈도우에서 홀수 1개 제거해야함
        if(odd >K){
            // start에서 홀수 찾기
            while(true){
                if(inputArray[start] % 2 ===1){
                    break;
                }
                start++;
            }
            odd--;
            start++;
        }
        longest = Math.max(end-start+1-odd,longest);
        end++;

    }

    console.log(longest);
    
})

