FROM mcr.microsoft.com/devcontainers/base:ubuntu

RUN apt-get update && \
    apt-get install -y software-properties-common && \
    apt-get install -y xz-utils && \
    apt-get install -y valgrind && \
	apt-get install -y man-db && \
	apt-get install -y cmake && \
    add-apt-repository ppa:deadsnakes/ppa && \
    apt-get update 

RUN apt-get install -y \
    python3.9 \
    python3.9-venv \
    python3.9-dev \
    python3-pip \
    python3-tk

RUN apt-get install -y \
    build-essential \
    pkg-config \
    libcairo2-dev \
    libgirepository1.0-dev \
    gir1.2-gtk-3.0 \
    libffi-dev \
    libssl-dev \
    libx11-dev \
    libxext-dev \
    libxrender-dev \
    libxtst-dev \
    libxi-dev \
    tigervnc-standalone-server \
    xfce4 \
    g++ \
    clang \
    libgl1-mesa-dev libglu1-mesa-dev\
    libx11-dev libxrandr-dev\
    libudev-dev \
    libfreetype-dev

WORKDIR /workspaces/

# Copia el archivo requirements.txt al contenedor
COPY requirements.txt /workspaces/

RUN pip install -r /workspaces/requirements.txt

CMD ["vncserver", "-fg"]