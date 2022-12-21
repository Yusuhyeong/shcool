//index내 canvas id 지정
let canvas = document.querySelector("#myCanvas");
let ctx = canvas.getContext("2d");

//공의 초기 위치
let x = canvas.width / 2;
let y = canvas.height - 30;

//볼의 위치 이동
let dx = 2;
let dy = -2;

//공의 지름
let ballRadius = 10;

// 패들
let paddleHeight = 10;
let paddleWidth = 85;
let paddleX = (canvas.width - paddleWidth) / 2;

// 키보드
let rightPressed = false;
let leftPressed = false;

// 벽돌
let brickRowCount = 5; // 5행
let brickColumnCount = 10; // 10열 짜리 벽돌 생성
let brickWidth = 85; // 가로 85
let brickHeight = 20; // 세로 20 짜리 벽돌 생성
let brickPadding = 10; // 벽돌 패딩 10 설성
let brickOffsetTop = 30; // 벽돌 윗 공간 설정
let brickOffsetLeft = 30; // 벽돌 왼쪽 공간 설정
let bricks = []; // 벽돌 배열

//벽돌 생성 반복문
for (let c = 0; c < brickColumnCount; c++) {
  bricks[c] = [];
  for (let r = 0; r < brickRowCount; r++) {
    bricks[c][r] = { x: 0, y: 0, status: 1 };
  }
}

//초기 점수 및 목숨 설정
let score = 0;
let lives = 3;

//키보드 및 마우스 이벤트 생성 함수
document.addEventListener("keydown", keyDownHandler, false);
document.addEventListener("keyup", keyUpHandler, false);
document.addEventListener("mousemove", mouseMoveHandler, false);

// 키보드가 눌렸을 때 (왼쪽, 오른쪽)
function keyDownHandler(e) {
  if (e.keyCode === 39) {
    rightPressed = true;
  } else if (e.keyCode === 37) {
    leftPressed = true;
  }
}

//키보드가 눌렸던 것을 땔 때 (왼쪽, 오른쪽)
function keyUpHandler(e) {
  if (e.keyCode === 39) {
    rightPressed = false;
  } else if (e.keyCode === 37) {
    leftPressed = false;
  }
}

// 마우스 커서
function mouseMoveHandler(e) {
  // 마우스 커서에 다른 위치 설정
  let relativeX = e.clientX - canvas.offsetLeft;
  //패들 가로의 가운데 위치하도록 설정
  if (
    relativeX > paddleWidth / 2 &&
    relativeX < canvas.width - paddleWidth / 2
  ) {
    paddleX = relativeX - paddleWidth / 2;
  }
}

// 벽돌에 닿았을 때
function collisionDetection() {
  // for문을 통한 벽돌의 개수에 대해서
  for (let c = 0; c < brickColumnCount; c++) {
    for (let r = 0; r < brickRowCount; r++) {
      let b = bricks[c][r];
      if (b.status === 1) { // 벽돌이 있는 상태에서
        if (
          x > b.x &&
          x < b.x + brickWidth &&
          y > b.y &&
          y < b.y + brickHeight
        ) {
          dy = -dy; // 공의 방향이 아래쪽으로 바뀐다면
          b.status = 0; // 그 위치에 벽돌은 없어진다.
          score++; // 점수는 1점 더한다.
          if (score === brickRowCount * brickColumnCount) {
            //점수와 벽돌의 개수가 같다면
            alert("YOU WIN, CONGRAULATIONS!");
            //문구와 함께 게임 종료
            document.location.reload();
          }
        }
      }
    }
  }
}

// 점수 (왼쪽 상단)
function drawScore() {
  ctx.font = "16px Arial";
  ctx.fillStyle = "#000";
  ctx.fillText("Score: " + score, 8, 20);
}

// 목숨 (오른쪽 상단)
function drawLives() {
  ctx.font = "16px Arial";
  ctx.fillStyle = "#000";
  ctx.fillText("Lives: " + lives, canvas.width - 65, 20);
}

// 공의 외관
function drawBall() {
  ctx.beginPath();
  ctx.arc(x, y, ballRadius, 0, Math.PI * 2);
  ctx.fillStyle = "#000";
  ctx.fill();
  ctx.closePath();
}

// 패들의 외관
function drawPaddle() {
  ctx.beginPath();
  ctx.rect(paddleX, canvas.height - paddleHeight, paddleWidth, paddleHeight);
  ctx.fillStyle = "#000";
  ctx.fill();
  ctx.closePath();
}

// 벽돌의 외관
function drawBricks() {
  for (let c = 0; c < brickColumnCount; c++) {
    for (let r = 0; r < brickRowCount; r++) {
      if (bricks[c][r].status === 1) { // 벽돌이 있으면 상태는 1
        let brickX = c * (brickWidth + brickPadding) + brickOffsetLeft;
        let brickY = r * (brickHeight + brickPadding) + brickOffsetTop;
        bricks[c][r].x = brickX;
        bricks[c][r].y = brickY;
        ctx.beginPath();
        ctx.rect(brickX, brickY, brickWidth, brickHeight);
        ctx.fillStyle = "#000";
        ctx.fill();
        ctx.closePath();
      }
    }
  }
}
// 공의 움직임
function draw() {
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  drawBricks();
  drawBall();
  drawPaddle();
  drawScore();
  drawLives();
  collisionDetection();

  //공이 캔버스 밖을 나가지 않도록 설정
  if (x + dx > canvas.width - ballRadius || x + dx < ballRadius) { // 가로에 대한 설정
    dx = -dx;
  }
  if (y + dy < ballRadius) { // 세로에 대한 설정
    dy = -dy;
  } else if (y + dy > canvas.height - ballRadius) { // 세로에 대한 설정
    if (x > paddleX && x < paddleX + paddleWidth) { // 패들에 대한 설정
      dy = -dy;
    } else { // 패들 밑으로 갈경우
      lives--; // 목숨이 떨어지고
      if (!lives) { // 목숨이 0이면
        alert("GAME OVER"); // 게임 종료
        document.location.reload();
      } else {
        x = canvas.width / 2;
        y = canvas.height - 30;
        //목숨이 떨어질 때마다 속도 증가
        dx--;
        dy++;
        //목숨 떨어질 때마다 패들 크기 감소
        paddleWidth = paddleWidth - 20;
        paddleX = (canvas.width - paddleWidth) / 2;
      }
    }
  }

  if (rightPressed && paddleX < canvas.width - paddleWidth) {
    paddleX += 7;
  } else if (leftPressed && paddleX > 0) {
    paddleX -= 7;
  }

  x += dx;
  y += dy;
  requestAnimationFrame(draw);
}

draw();
