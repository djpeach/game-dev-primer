import pygame
pygame.init()

w = 500
h = 500

screen = pygame.display.set_mode([w, h])
pygame.display.set_caption("Primer")

clock = pygame.time.Clock()
elapsedTime = 0
fps = 1 / 60

x = 250
y = 250
r = 75
v = 5

running = True
while running:
  clock.tick()
  elapsedTime += clock.get_time()

  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      running = False
  print(elapsedTime)
  while(elapsedTime / 1000 > fps):
    elapsedTime -= fps * 1000

    keys = pygame.key.get_pressed()
    if keys[pygame.K_w]:
      if (y - v > r):
        y -= v
      else:
        y = r
    if keys[pygame.K_s]:
      if (y + v < h - r):
        y += v
      else:
        y = h - r
    if keys[pygame.K_a]:
      if (x - v > r):
        x -= v
      else:
        x = r
    if keys[pygame.K_d]:
      if (x + v < w - r):
        x += v
      else:
        x = h - r

  screen.fill((255, 255, 255))
  pygame.draw.circle(screen, (0, 0, 255), (x, y), r)

  pygame.display.flip()

pygame.quit()
