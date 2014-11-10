// por enquanto nao temos includes

// o main nao tem argumentos e nao retorna nada
void main() {
    int i, j;

    // Mapa = 30 x 40

    // nao se esquecer de contar o \0 no fim de cada string
    char mapa[30][29] = {
        { "############################" },
        { "#............##............#" }, 
        { "#.####.#####.##.#####.####.#" },
        { "#.####.#####.##.#####.####.#" },
        { "#.####.#####.##.#####.####.#" },
        { "#..........................#" },
        { "#.####.##.########.##.####.#" },
        { "#.####.##.########.##.####.#" },
        { "#......##....##....##......#" },
        { "######.##### ## #####.######" },
        { "     #.##          ##.#     " },
        { "     #.## ###--### ##.#     " },
        { "######.## #      # ##.######" },
        { "      .   #      #   .      " },
        { "######.## #      # ##.######" },
        { "     #.## ######## ##.#     " },
        { "     #.##          ##.#     " },
        { "     #.## ######## ##.#     " },
        { "######.## ######## ##.######" },
        { "#............##............#" },
        { "#.####.#####.##.#####.####.#" },
        { "#.####.#####.##.#####.####.#" },
        { "#...##...          ...##...#" },
        { "###.##.## ######## ##.##.###" },
        { "###.##.## ######## ##.##.###" },
        { "#......##    ##    ##......#" },
        { "#.########## ## ##########.#" },
        { "#.########## ## ##########.#" },
        { "#...........    ...........#" },
        { "############################" }
    };
    
    // imprime o mapa
    for(i = 0; i < 30; i++)
        printf(i, 0, "%s", mapa[i]);

    // imprime informacoes do jogo
    printf(1, 29, "Jogo do");
    printf(2, 29, "Pacman v2.0");
    printf(4, 29, "Controles:");
    printf(5, 29, "w - Sobe");
    printf(6, 29, "a - Esq");
    printf(7, 29, "s - Desce");
    printf(8, 29, "d - Dir");

    // posicao inicial do personagem
    int pos_x = 1;
    int pos_y = 1;

    // caracter do personagem
    char c = 'p';

    // imprime o personagem
    printf(pos_x, pos_y, "%c", c);

    // score
    int score = 0;
    printf(10, 29, "Score: %d", score);

    // vidas
    int vidas = 3;
    printf(11, 29, "Vidas: %d", vidas);

    // tecla pressionada pelo usuario
    char key = 'l';

    // loop do jogo
    while(key != 'q') {
        // recebe a tecla
        key = getch();

        // esquerda y--
        if(key == 'a' && pos_y > 1) {   // lembrar que nao tem numero negativo

            // se for muro, nao move
            if(mapa[pos_x][pos_y-1] == '#')
                continue;

            printf(pos_x, pos_y, " ");  // apaga a posicao anterior
            pos_y--;
            printf(pos_x, pos_y, "%c", c);
        }

        // direita y++
        if(key == 'd' && pos_y < 27) {

            // se for muro, nao move
            if(mapa[pos_x][pos_y+1] == '#')
                continue;

            printf(pos_x, pos_y, " ");  // apaga a posicao anterior
            pos_y++;
            printf(pos_x, pos_y, "%c", c);
        }

        // desce x++
        if(key == 's' && pos_x < 28) {

            // se for muro, nao move
            if(mapa[pos_x+1][pos_y] == '#')
                continue;

            printf(pos_x, pos_y, " ");  // apaga a posicao anterior
            pos_x++;
            printf(pos_x, pos_y, "%c", c);
        }

        // sobe x--
        if(key == 'w' && pos_x > 1) {

            // se for muro, nao move
            if(mapa[pos_x-1][pos_y] == '#')
                continue;

            printf(pos_x, pos_y, " ");  // apaga a posicao anterior
            pos_x--;
            printf(pos_x, pos_y, "%c", c);
        }

        // atualiza o mapa, se for comida
        if(mapa[pos_x][pos_y] == '.') {
            score++;
            printf(10, 36, "%d", score);
            mapa[pos_x][pos_y] = ' ';
        }
    }

    return;
}
