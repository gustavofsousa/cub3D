<h1 align="center">cub3D</h1>

<p align="center">
  <img src="https://img.shields.io/badge/linguagem-C-blue.svg" alt="Linguagem">
  <img src="https://img.shields.io/badge/42-School-black.svg" alt="42 School">
  <img src="https://img.shields.io/badge/status-completo-brightgreen.svg" alt="Status">
</p>

<p align="center">
  Um jogo de labirinto 3D em primeira pessoa construído do zero em C usando ray-casting — inspirado no motor original do Wolfenstein 3D.
</p>

<p align="center">
  <a href="README.md">🇺🇸 Read in English</a>
</p>

---

## Por que este projeto importa

> "Este projeto me ensinou como os primeiros jogos 3D eram renderizados — usando ray-casting em vez de um motor 3D real, projetando um mapa 2D em perspectiva 3D em tempo real. Aprendi a matemática por trás do campo de visão, projeção angular, mapeamento de texturas e design de game loop. Esse é o fundamento de todo motor gráfico, do desenvolvimento de jogos à realidade aumentada."

Ray-casting é a otimização de renderização original que tornou possíveis os jogos 3D em tempo real no início dos anos 90. Entendê-la dá uma intuição profunda sobre como pipelines de renderização modernos — incluindo shaders de GPU e motores de AR — funcionam.

---

## Preview

Uma perspectiva em primeira pessoa renderizada a partir de um arquivo de mapa `.cub`:

```
111111
100001
1N0001
100001
111111
```

- `1` = parede
- `0` = espaço aberto
- `N/S/E/W` = spawn do jogador + direção inicial

---

## O que foi construído

- **Ray-caster** — lança raios do POV do jogador para calcular distâncias e alturas das paredes
- **Renderização de texturas** — carrega texturas `.xpm` e as mapeia nas paredes com base na posição de hit do raio
- **Validador de mapa** — verifica se o mapa está completamente fechado, tem exatamente um jogador e apenas caracteres válidos
- **Sistema de movimento** — movimento WASD + rotação esquerda/direita com detecção de colisão
- **Minimapa** (bônus) — visão aérea em tempo real do labirinto
- **Renderização de cores** — cores configuráveis de chão e teto via arquivo `.cub`

---

## Um detalhe técnico que se destaca

O projeto é organizado em subsistemas distintos — `raycast/`, `validate_map/`, `interpretate_map/`, `texture/`, `color/`, `movements/`, `minimap/` — cada um em seu próprio diretório com responsabilidades focadas. Esse tipo de estrutura de diretórios orientada a domínio escala bem e torna a base de código navegável, um padrão visto em game engines em produção e grandes projetos C.

---

## Como usar

### Pré-requisitos

```bash
# No Ubuntu/Debian
sudo apt-get install libxext-dev libx11-dev libmlx-dev
```

```bash
git clone https://github.com/gustavofsousa/cub3D.git
cd cub3D
make
```

### Executando

```bash
./cub3D maps/mapa1.cub
```

### Formato do mapa (`.cub`)

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100001
1N0001
100001
111111
```

### Controles

| Tecla | Ação |
|---|---|
| `W` `A` `S` `D` | Mover frente / strafe esquerda / ré / strafe direita |
| `←` `→` | Rotacionar câmera |
| `ESC` | Sair |

---

## Estrutura do projeto

```
cub3D/
├── source/
│   ├── main.c
│   ├── setup.c
│   ├── render_game.c
│   ├── raycast/          # Algoritmo de ray-casting
│   ├── texture/          # Carregamento de texturas XPM
│   ├── color/            # Renderização de cores chão/teto
│   ├── validate_map/     # Lógica de validação do mapa
│   ├── interpretate_map/ # Parsing do arquivo de mapa
│   ├── movements/        # Movimento e colisão do jogador
│   ├── minimap/          # Bônus: minimapa aéreo
│   └── hooks_keyboard.c  # Tratamento de input
├── include/
│   ├── cub3d.h
│   ├── structs.h
│   └── constants.h
├── maps/                 # Arquivos de mapa .cub de exemplo
├── textures/             # Arquivos de textura XPM
└── libft/
```

---

## Habilidades demonstradas

- Algoritmo de renderização ray-casting (DDA — Análise Diferencial Digital)
- Carregamento de texturas XPM e mapeamento no nível de pixel
- Game loop em tempo real com tratamento de eventos de teclado
- Validação complexa de mapa (flood fill, verificação de bordas)
- Arquitetura modular em grande projeto C multi-arquivo
- Trigonometria aplicada à projeção de câmera (FOV, cálculos de ângulo)

---

## Licença

Este projeto foi desenvolvido como parte do currículo da [42 School](https://42.fr).

---

<p align="center">Feito com ☕ na 42 Rio de Janeiro</p>
