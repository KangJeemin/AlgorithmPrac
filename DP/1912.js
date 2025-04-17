const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", (line) => {
  input.push(line);
}).on("close", () => {
  const N = +input[0];
  const nums = input[1].split(" ").map(Number);

  /**
   * 배열에서 연속하는 최대합 출력
   * @param len - 배열의 길이
   * @param arr - 배열
   */
  const dp = (len, arr) => {
    const memo = [arr[0]];
    // 배열 전체에서의 최댓값
    let max = arr[0];
    for (let i = 1; i < len; i++) {
      memo[i] = Math.max(memo[i - 1] + arr[i], arr[i]);
      max = Math.max(memo[i], max);
    }
    return max;
  };
  console.log(dp(N, nums));
});