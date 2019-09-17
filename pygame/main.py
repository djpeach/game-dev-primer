import pygame
pygame.init()

w = 500
h = 500

screen = pygame.display.set_mode([w, h])
pygame.display.set_caption("Primer")

x = 250
y = 250
r = 75
v = 5

i = 0

running = True
while running:
  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      running = False

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

  # This will print much slower than the C++/SFML version
  i += 1
  print("Loop:", i)

  screen.fill((255, 255, 255))
  pygame.draw.circle(screen, (0, 0, 255), (x, y), r)

  pygame.display.flip()

pygame.quit()
