const readline = require('readline');

const rl = readline.Interface({
    input:process.stdin,
    output:process.stdout,
});

const input = [];
rl.on("line",(line)=>{
    input.push(line.trim());
}).on("close",()=>{
    const [N, M] = input[0].split(' ').map(Number);
    const treeinput = input[1].split(' ').map(Number);
    const tree = Array.from({ length: N }, () => []);
    const complement = input.slice(2,2+M).map(line=> line.split(' ').map(Number));
    const complementSum = Array(N).fill(0);
    const AnsComplementSum = Array(N).fill(0);

    function setTree(tree,treeinput){
        for(let i=0;i<treeinput.length;i++){
            let childnode = treeinput[i];
            if(childnode==-1) continue;
            tree[childnode-1].push(i);
        }
    }

    setTree(tree,treeinput);

    function setCompelementSum () {
        complement.forEach(e=>{
            complement[e[0]-1]+=w;
        })
    }
    setCompelementSum();

    function calculateComplement(complement){
        complement.forEach(element => {
            let node = element[0]-1;
            let w = element[1];
            const DFS = (node,w)=>{
                complementSum[node]+=w;
                for(let i=0;i<tree[node].length;i++){
                    DFS(tree[node][i],w);
                }
            }
            DFS(node,w);
        });
    }

    calculateComplement(complement);


    console.log(complementSum.join(' '));


    
})