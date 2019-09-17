import pygame
pygame.init()

w = 500
h = 500

screen = pygame.display.set_mode([w, h])
pygame.display.set_caption("Primer - pygame")

clock = pygame.time.Clock()
elapsedTime = 0
fps = 1 / 60

x = 250
y = 250
r = 75
v = 500

running = True
while running:
  clock.tick()
  elapsedTime += clock.get_time()

  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      running = False

  while(elapsedTime / 1000 > fps):
    elapsedTime -= fps * 1000

    keys = pygame.key.get_pressed()
    if keys[pygame.K_w]:
      if (y - (v * fps) > r):
        y -= (v * fps)
      else:
        y = r
    if keys[pygame.K_s]:
      if (y + (v * fps) < h - r):
        y += (v * fps)
      else:
        y = h - r
    if keys[pygame.K_a]:
      if (x - (v * fps) > r):
        x -= (v * fps)
      else:
        x = r
    if keys[pygame.K_d]:
      if (x + (v * fps) < w - r):
        x += (v * fps)
      else:
        x = h - r

  screen.fill((255, 255, 255))
  pygame.draw.circle(screen, (0, 0, 255), (int(x), int(y)), r)

  pygame.display.flip()

pygame.quit()
