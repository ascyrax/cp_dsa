
void keyPressed()
{
  println(keyCode);
  if (keyCode == 37 || keyCode == 65)
  {
    snakeBody.get(0).speedX = -1;
    snakeBody.get(0).speedY = 0;
  }
  else if (keyCode == 38 || keyCode == 87)
  {
    snakeBody.get(0).speedX = 0;
    snakeBody.get(0).speedY = -1;
  }
  else if (keyCode == 39 || keyCode == 68)
  {
    snakeBody.get(0).speedX = 1;
    snakeBody.get(0).speedY = 0;
  }
  else if (keyCode == 40 || keyCode == 83)
  {
    snakeBody.get(0).speedX = 0;
    snakeBody.get(0).speedY = 1;
  }
}