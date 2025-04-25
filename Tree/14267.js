const readline = require('readline');

const rl = readline.createInterface({  // 오타 수정: Interface → createInterface
    input: process.stdin,
    output: process.stdout,
});

const input = [];
rl.on("line", (line) => {
    input.push(line.trim());
}).on("close", () => {
    const [N, M] = input[0].split(' ').map(Number);
    const treeinput = input[1].split(' ').map(Number);
    const tree = Array.from({ length: N }, () => []);
    const complementSum = Array(N).fill(0);

    // 트리 구성
    for (let i = 0; i < N; i++) {
        const parent = treeinput[i];
        if (parent !== -1) {
            tree[parent - 1].push(i);
        }
    }

    // 칭찬 누적합 입력
    for (let i = 2; i < 2 + M; i++) {
        const [employee, praise] = input[i].split(' ').map(Number);
        complementSum[employee - 1] += praise;
    }

    // 누적 DFS
    const DFS = (node, acc) => {
        const total = acc + complementSum[node];
        complementSum[node] = total;
        for (const child of tree[node]) {
            DFS(child, total);
        }
    };
    DFS(0, 0);

    console.log(complementSum.join(' '));
});
