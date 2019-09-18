import pygame
pygame.init()

w = 500
h = 500

x = 250
y = 250
r = 50
v = 500

screen = pygame.display.set_mode([w, h])
pygame.display.set_caption("Primer - pygame")
bg = pygame.image.load("assets/images/bg.jpg")
ship = pygame.image.load("assets/images/ship.png")
ship = pygame.transform.scale(ship, (r * 2, r * 2))

clock = pygame.time.Clock()
elapsedTime = 0
fps = 1 / 60
prevAng = 0
angle = 0

running = True
while running:
  clock.tick()
  elapsedTime += clock.get_rawtime()

  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      running = False

  while(elapsedTime / 1000 > fps):
    elapsedTime -= fps * 1000

    keys = pygame.key.get_pressed()
    if keys[pygame.K_w]:
      angle = 0
      if (y - (v * fps) > -h / 2 - r):
        y -= (v * fps)
    if keys[pygame.K_s]:
      angle = 180
      if ((y + h) + (v * fps) < bg.get_rect().height - h / 2 - r):
        y += (v * fps)
    if keys[pygame.K_a]:
      angle = 90
      if (x - (v * fps) > -w / 2 - r):
        x -= (v * fps)
    if keys[pygame.K_d]:
      angle = 270
      if ((x + w) + (v * fps) < bg.get_rect().width - w / 2 - r):
        x += (v * fps)

  if angle == 0 and prevAng != 0:
    ship = pygame.transform.rotate(ship, -prevAng)
    prevAng = 0
  if angle == 180 and prevAng != 180:
    ship = pygame.transform.rotate(ship, 180 - prevAng)
    prevAng = 180
  if angle == 90 and prevAng != 90:
    ship = pygame.transform.rotate(ship, 90 - prevAng)
    prevAng = 90
  if angle == 270 and prevAng != 270:
    ship = pygame.transform.rotate(ship, 270 - prevAng)
    prevAng = 270

  screen.fill((255, 255, 255))
  screen.blit(bg, (int(-x) - r - w / 2, int(-y) - r - h / 2))
  screen.blit(ship, (250 - r, 250 - r))

  pygame.display.flip()

pygame.quit()
