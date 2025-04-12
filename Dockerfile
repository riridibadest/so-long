FROM ubuntu:latest

# Install necessary packages
RUN apt-get update && apt-get install -y \
    build-essential \
    valgrind \
    libglfw3-dev \
    libglfw3 \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory
WORKDIR /app

# Copy your source code and map file into the container
COPY . .

# Ensure the map file is in the correct location
COPY map/map1.ber /app/map1.ber

# Compile your application
RUN gcc -Wall -Wextra -Werror -o map_test map_test.c

# Command to run Valgrind
CMD ["valgrind", "--leak-check=full", "./map_test", "/app/map1.ber"]