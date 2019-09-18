import pygame
pygame.init()

w = 800
h = 800
r = 50

x = w / 2 - r
y = h / 2 - r
vx = 0
vy = 0
v = 500

screen = pygame.display.set_mode([w, h])
pygame.display.set_caption("Primer - pygame")
bg = pygame.image.load("assets/images/bg.jpg")
origShip = pygame.image.load("assets/images/ship.png")
origShip = pygame.transform.scale(origShip, (r * 2, r * 2))
ship = origShip

clock = pygame.time.Clock()
elapsedTime = 0
fps = 1 / 60
prevAng = 0
angle = 0

running = True
while running:
  clock.tick(60)
  elapsedTime += clock.get_time()

  for event in pygame.event.get():
    if event.type == pygame.QUIT:
      running = False

  while(elapsedTime / 1000 > fps):
    elapsedTime -= fps * 1000

    keys = pygame.key.get_pressed()
    if keys[pygame.K_w]:
      if keys[pygame.K_a]:
        ship = pygame.transform.rotate(origShip, -315)
      elif keys[pygame.K_d]:
        ship = pygame.transform.rotate(origShip, -45)
      else:
        ship = pygame.transform.rotate(origShip, 0)
      if y + r - (v * fps) > h / 2:
        y -= (v * fps)
      elif vy - (v * fps) > bg.get_rect().top:
        vy -= (v * fps)
      elif y - (v * fps) > bg.get_rect().top:
        y -= (v * fps)
    if keys[pygame.K_s]:
      if keys[pygame.K_a]:
        ship = pygame.transform.rotate(origShip, -225)
      elif keys[pygame.K_d]:
        ship = pygame.transform.rotate(origShip, -135)
      else:
        ship = pygame.transform.rotate(origShip, 180)
      if y + r + (v * fps) < h / 2:
        y += (v * fps)
      elif vy + h + (v * fps) < bg.get_rect().bottom:
        vy += (v * fps)
      elif y + ship.get_rect().height + (v * fps) < h:
        y += (v * fps)
    if keys[pygame.K_a]:
      if keys[pygame.K_w]:
        ship = pygame.transform.rotate(origShip, -315)
      elif keys[pygame.K_s]:
        ship = pygame.transform.rotate(origShip, -225)
      else:
        ship = pygame.transform.rotate(origShip, -270)
      if x + r - (v * fps) > w / 2:
        x -= (v * fps)
      elif vx - (v * fps) > bg.get_rect().left:
        vx -= (v * fps)
      elif x - (v * fps) > bg.get_rect().left:
        x -= (v * fps)
    if keys[pygame.K_d]:
      if keys[pygame.K_w]:
        ship = pygame.transform.rotate(origShip, -45)
      elif keys[pygame.K_s]:
        ship = pygame.transform.rotate(origShip, -135)
      else:
        ship = pygame.transform.rotate(origShip, -90)
      if x + r + (v * fps) < w / 2:
        x += (v * fps)
      elif vx + h + (v * fps) < bg.get_rect().right:
        vx += (v * fps)
      elif x + ship.get_rect().height + (v * fps) < w:
        x += (v * fps)

    # if angle != prevAng:
    #   print(angle, prevAng, angle - prevAng)
    #   ship = pygame.transform.rotate(ship, angle - prevAng)
    #   prevAng = angle

  screen.fill((255, 255, 255))
  screen.blit(bg, (int(-vx), int(-vy)))
  screen.blit(ship, (int(x), int(y)))

  pygame.display.flip()

pygame.quit()
