#include <stdio.h>

struct Chip8
{
    unsigned char memory[4096];
    unsigned char v[16];
    unsigned short i;
    unsigned short pc;
    unsigned short stack[16];
    unsigned short sp;
    unsigned char delay_timer;
    unsigned char sound_timer;
    unsigned char display[64 * 32];
    unsigned char keypad[16];
};
void chip8_init(struct Chip8 *chip8);
void create_test_rom(struct Chip8 *chip8);
void chip8_execute(struct Chip8 *chip8);
void clear_display(struct Chip8 *chip8);
void draw_pixel(struct Chip8 *chip8, int x, int y);
void draw_sprite(struct Chip8 *chip8, int x, int y, int height);
void print_display(struct Chip8 *chip8);

void clear_display(struct Chip8 *chip8)
{
    for (int i = 0; i < 64 * 32; i++)
    {
        chip8->display[i] = 0;
    }
    printf(" Display cleared\n");
}

void draw_pixel(struct Chip8 *chip8, int x, int y)
{
    x = x % 64;
    y = y % 32;

    int index = y * 64 + x;
    chip8->display[index] ^= 1;

    if (chip8->display[index] == 0)
    {
        chip8->v[0xF] = 1;
    }
}

void draw_sprite(struct Chip8 * chip8, int x, int y, int height)
    {
        printf(" Drawing sprite at (%d, %d), height=%d\n", x, y, height);
        chip8->v[0xF] = 0;

        for (int row = 0; row < height; row++)
        {
            unsigned char sprite_byte = chip8->memory[chip8->i + row];

            for (int col = 0; col < 8; col++)
            {
                if (sprite_byte & (0x80 >> col))
                {
                    draw_pixel(chip8, x + col, y + row);
                }
            }
        }
    }
void print_display(struct Chip8 * chip8)
    {
        printf("\n--- DISPLAY (64x32) ---\n");

        for (int y = 0; y < 32; y++)
        {
            for (int x = 0; x < 64; x++)
            {
                int index = y * 64 + x;
                printf("%c", chip8->display[index] ? '#' : '.');
            }
            printf("\n");
        }
        printf("------------------------\n");
    }

void chip8_init(struct Chip8 *chip8)
{
    chip8->pc = 0x200;
    chip8->sp = 0;
    chip8->i = 0;
    chip8->delay_timer = 0;
    chip8->sound_timer = 0;

    for (int i = 0; i < 16; i++)
    {
        chip8->v[i] = 0;
    }

    for (int i = 0; i < 4096; i++)
    {
        chip8->memory[i] = 0;
    }

    for (int i = 0; i < 16; i++)
    {
        chip8->stack[i] = 0;
    }
}

void create_test_rom(struct Chip8 *chip8)
{
    chip8->memory[0x300] = 0xF0;
    chip8->memory[0x301] = 0xF0;
    chip8->memory[0x200] = 0xA3;
    chip8->memory[0x201] = 0x00;
    chip8->memory[0x202] = 0x60;
    chip8->memory[0x203] = 0x0A;
    chip8->memory[0x204] = 0x61;
    chip8->memory[0x205] = 0x0A;
    chip8->memory[0x206] = 0xD0;
    chip8->memory[0x207] = 0x15;
    chip8->memory[0x208] = 0x12;
    chip8->memory[0x209] = 0x00;

    printf("Test ROM:\n");
    printf(" Sprite at 0x300: 0xF0 0xF0\n");
    printf(" I = 0x300\n");
    printf(" V0 = 10, V1 = 10\n");
    printf(" Draw 5-byte sprite\n");
}

void chip8_execute(struct Chip8 *chip8)
{
    unsigned short opcode = (chip8->memory[chip8->pc] << 8) | chip8->memory[chip8->pc + 1];
    printf("Opcode: 0x%04X at PC: 0x%X\n", opcode, chip8->pc);

    switch (opcode & 0xF000)
    {
    case 0x0000:
        switch (opcode)
        {
        case 0x00E0:
            clear_display(chip8);
            chip8->pc += 2;
            break;
        default:
            chip8->pc += 2;
            break;
        }
        break;
    case 0x6000:
    {
        int reg = (opcode & 0x0F00) >> 8;
        unsigned char value = opcode & 0x00FF;
        chip8->v[reg] = value;
        printf(" Set V%d = %d (0x%02X)\n", reg, value, value);
        chip8->pc += 2;
        break;
    }

    case 0xD000:
    {
        int x_reg = (opcode & 0x0F00) >> 8;
        int y_reg = (opcode & 0x00F0) >> 4;
        int height = opcode & 0x000F;

        unsigned char x_pos = chip8->v[x_reg];
        unsigned char y_pos = chip8->v[y_reg];

        draw_sprite(chip8, x_pos, y_pos, height);
        chip8->pc += 2;
        break;
    }

    case 0xA000:
        chip8->i = opcode & 0x0FFF;
        printf(" Set I = 0x%X\n", chip8->i);
        chip8->pc += 2;
        break;

    case 0x1000:
        chip8->pc = opcode & 0x0FFF;
        printf("Jumped to 0x%X\n", chip8->pc);
        break;

    default:
        printf("Unknown opcode\n");
        chip8->pc += 2;
        break;
    }
}

int main()
{
    struct Chip8 chip8;
    chip8_init(&chip8);

    create_test_rom(&chip8);

    printf("---Starting execution---\n");

    for (int step = 0; step < 10; step++)
    {
        printf("\nStep %d:\n", step + 1);
        chip8_execute(&chip8);

        if (step == 3 || step == 8)
        {
            print_display(&chip8);
        }
    }
    return 0;
}
