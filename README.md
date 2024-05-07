# Semaforo-ESP32
 - Esse é um Projeto de uma série de projetos estudos de programação #01 [PRJT-7]
### Como Rodar
  Esse projeto foi simulado no [Wi](https://wokwi.com/), caso que queria simular lá basta copiar o conteúdo do [diagram.ja](https://github.com/JoaoBMC/Semaforo-ESP32/blob/main/diagram.json) no diagram.json do site e copiar o codigo [src/main.cpp](https://github.com/JoaoBMC/Semaforo-ESP32/blob/main/src/main.cpp) para a main.cpp no [Wi](https://wokwi.com/).
## Discrição
- Este projeto envolve a simulação de um sistema de semáforo para veículos e pedestres. Ele inclui um botão de acionamento e um contador regressivo que indica o tempo restante para a travessia dos pedestres.
## Sinal de Veículos (SV)
- LED Vermelho: indica que o veiculo precisa parar e aguardar.
- LED Amarelo: indica que a fase verde está prestes a terminar, os condutores devem parar, caso ainda não tenham atravessado o cruzamento.
- LED Verde:  indica que os veículos podem avançar com segurança.
    
   ### Funcionamento:
    - O Led verde ficara aceso por 30 segundos em seguida se apagará. O LED amarelo será aceso por 3 segundos e, após esse tempo, se apagara. Então o LED vermelho ficará aceso por 20 segundos. Após esse tempo, o LED apagará e verde acenderá novamente, reiniciando o ciclo.

## Sinal De Pedestre (SP)
- LED Vermelho: indica que o pedestre precisa parar e aguardar.
- LED Verde:  indica que os pedestres podem atravessar a faixa de pedestre com segurança.
- Botão de Passagem: faz com que o pedestre possa solicita o fechamento do sinal de veículos para a passagem.
  
    ### Funcionamento:
    - O pedestre pode aguardar o ciclo do sinal de veículos passa para o vermelho e o LED do Sinal de Pedestre ficar Verde ou acionar o Botão de Passagem para que iniciar o fechamento (vermelho) do sinal de veículos e abrir (verde) o de pedestre e mostrando uma contagem regressiva (de 20 segundos) de quanto tempo falta para o sinal de pedestre ficar vermelho e o de veículos ficar verde.
    
    ## Material
    - Esp32
    - LEDs
        - 2 Vermelhos
        - 1 Amarelo
        - 2 Verdes
    - Display de 7 Seguimentos 2 Dígitos
    - Botão tipo pushButton
    - 15 resistores de 1k ohm

## Requisitos

### Funcionais

- Os LEDs Vermelho, Amarelo, Verde do sinal do Veiculo deve acender e apagar.
- Os LEDs Vermelho e verde do Sinal do Pedestre deve acender e apagar
- O Botão deve acionar o sinal de pedestre a qualquer momento
- O Display deve mostrar o tempo restante para o termino do sinal de pedestre.

### Não funcionais

- Os LEDs do Sinal do veiculo temem que ter a ordem de Verde → Amarelo → Vermelho → Verde
- Os LEDs do sinal do veiculo devem ter os tempos:
    - Verde 30 Segundos
    - Amarelo 2 segundos
    - Vermelho 20 segundos
- O contador deve está desligado caso nao seja acionado pelo pedestre## Esquemático
 
![Esquematico projeto PRJT-7](https://github.com/JoaoBMC/Semaforo-ESP32/assets/64325336/bbca8b85-76b6-4fe9-843d-d67d4960e66f)

| Componente | GPIO |
| --- | --- |
| VERMELHO (SV) | 15 |
| AMARELO (SV) | 2 |
| VERDE (SV) | 0 |
| BOTÃO (SP) | 4 |
| VERMELHO (SP) | 16 |
| VERDE (SP) | 17 |
| DISPLAY DG 01 (SP) | 7 |
| DISPLAY DG 02 (SP) | 8 |
| DISPLAY A (SP) | 5 |
| DISPLAY B (SP) | 18 |
| DISPLAY C (SP) | 19 |
| DISPLAY D (SP) | 21 |
| DISPLAY E (SP) | 22 |
| DISPLAY F (SP) | 23 |
| DISPLAY G (SP) | 13 |
| DISPLAY DP (SP) | 12 |

### Display de 7 Seguimentos 2 dígitos (Esquemático)
![Esquematico display 7seg 2 digitos PRJT-7](https://github.com/JoaoBMC/Semaforo-ESP32/assets/64325336/3520efa6-7457-4df1-9356-5bf1635797de)



