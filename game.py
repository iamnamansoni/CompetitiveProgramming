import pygame
import random

# Initialize pygame
pygame.init()

# Screen dimensions
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600

# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
GREEN = (0, 255, 0)

# Set up the screen
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Catch the Falling Apples")

# Clock for controlling the frame rate
clock = pygame.time.Clock()

# Basket properties
basket_width = 100
basket_height = 20
basket_x = SCREEN_WIDTH // 2 - basket_width // 2
basket_y = SCREEN_HEIGHT - basket_height - 10
basket_speed = 10

# Apple properties
apple_radius = 10
apple_x = random.randint(apple_radius, SCREEN_WIDTH - apple_radius)
apple_y = -apple_radius
apple_speed = 5

# Score
score = 0
font = pygame.font.Font(None, 36)

# Game loop
running = True
while running:
    screen.fill(WHITE)

    # Event handling
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Basket movement
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT] and basket_x > 0:
        basket_x -= basket_speed
    if keys[pygame.K_RIGHT] and basket_x < SCREEN_WIDTH - basket_width:
        basket_x += basket_speed

    # Update apple position
    apple_y += apple_speed

    # Check if the apple is caught
    if basket_y < apple_y + apple_radius < basket_y + basket_height and basket_x < apple_x < basket_x + basket_width:
        score += 1
        apple_x = random.randint(apple_radius, SCREEN_WIDTH - apple_radius)
        apple_y = -apple_radius
        apple_speed += 0.2  # Gradually increase the speed

    # Check if the apple falls off the screen
    if apple_y > SCREEN_HEIGHT:
        running = False  # End the game

    # Draw the basket
    pygame.draw.rect(screen, GREEN, (basket_x, basket_y, basket_width, basket_height))

    # Draw the apple
    pygame.draw.circle(screen, RED, (apple_x, apple_y), apple_radius)

    # Draw the score
    score_text = font.render(f"Score: {score}", True, BLACK)
    screen.blit(score_text, (10, 10))

    # Update the display
    pygame.display.flip()

    # Cap the frame rate
    clock.tick(30)

# End of the game
pygame.quit()
