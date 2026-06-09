🛰️ Rad Anux: Radian Anomaly Nucleus & Unit Experiment


📖 Descrição do Projeto
O Rad Anux é uma plataforma de testes focada em software aeroespacial adaptada para o ambiente de microcontroladores. O projeto simula o impacto físico da radiação cósmica em componentes eletrônicos comerciais (CubeSats), especificamente o fenômeno conhecido como Single Event Upset (SEU) ou Bit-Flip, que causa a corrupção de variáveis críticas em memória.


🎯 Objetivo da Solução
O objetivo principal é criar um "Satélite de Bancada" que permita aos engenheiros testar algoritmos de auto-recuperação (redundância) contra falhas de hardware antes do lançamento. A solução automatiza e democratiza os testes de resiliência espacial de forma barata e ágil, evitando falhas catastróficas em órbita que poderiam custar milhões.


🔌 Componentes Utilizados (Simulador)
1x Arduino Uno R3 (Representando o Computador de Bordo)

1x Display LCD 16x2 I2C (Dashboard de Monitoramento)

1x Potenciômetro (Controlador do Fator de Radiação Orbital)

1x Botão Pushbutton (Gatilho de Injeção de Falha)

2x LEDs (Verde para Sucesso/Recuperação, Vermelho para Falha Crítica/Crash)

2x Resistores 220Ω

Jumpers e Protoboard


⚙️ Explicação do Funcionamento
O sistema inicia no modo de configuração, onde o usuário ajusta um potenciômetro para definir o "Fator k" (nível de radiação da órbita, de 1% a 10%). Ao pressionar o botão de início, o Arduino inicia a simulação de voo rastreando uma variável crítica (Altitude). O Rad Anux então força um Bit-Flip matemático nessa variável, simulando o impacto da radiação.

O software tenta se auto-corrigir buscando o dado em um registro de redundância. Se o nível de radiação configurado for tolerável, o sistema se recupera (LED Verde) e gera um Score de Resiliência alto. Se a radiação for extrema, o sistema sofre um Crash (LED Vermelho), e o Score cai drasticamente.


🏗️ Estrutura do Circuito
O circuito foi desenhado para facilitar a interação e leitura:

Display I2C: Pinos A4 (SDA) e A5 (SCL) para comunicação de dados.

Controle de Radiação: Potenciômetro ligado ao pino analógico A0.

Atuador de Teste: Botão com resistor Pull-Up interno no Pino Digital 2.

Feedback Visual: LEDs Verde (Pino 8) e Vermelho (Pino 9).


▶️ Instruções de Execução
Acesse o link do simulador Wokwi: https://wokwi.com/projects/466312381784302593

Clique no botão de "Play" (Start Simulation).

Clique no potenciômetro e gire-o para ajustar o nível de radiação desejado no display.

Pressione o botão para iniciar a injeção do Single Event Upset.

Observe o alerta de falha no LCD e verifique se o sistema acenderá o LED Verde (Recuperado) ou Vermelho (Crash), além da nota final (Score).


👥 Nome Completo dos Integrantes do Grupo
Pedro Marques - RM: 569307

Evandro Marcondes - RM: 572473

Enzo Alves - RM: 569665

Renan Queiroz - RM: 569077

Raphael de Oliveira - RM: 571065


🔗 Passo 4: O Link do Wokwi
Não se esqueça de substituir o https://wokwi.com/projects/466312381784302593 no texto acima pelo link real do seu projeto. Para pegar esse link no Wokwi, basta clicar em "Share" (no menu superior) e copiar a URL fornecida.
