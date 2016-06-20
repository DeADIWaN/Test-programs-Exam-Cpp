% ИГРА "Поле Чудес"
% Отгадайте слово, ответив на вопрос!


function fieldOfDream(varargin)
cla
global question;            % вопрос
global ind;                 % индекс для пробега по letters
global isLetterInBox;       % вектор для проверки наличия буквы в квадрате
global letters;             % алфавит
letters = {'а','б','в','г','д','е','ё','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю','я'};
global answerWord;          % ответ на вопрос
global uesrWord;            % ответ пользователя
global questionBasa;        % база вопросов
global answerWordBasa;      % база ответов
questionBasa = {'Буквы складываются в..','Что может быть восковым?',...
    'Чем рисуют на асфальте?','Что можно открыть ключом?',...
    'Где живёт король?','Какой лучший головной убор?',...
    'Что есть у Зорро?','Что поможет скрыть свое лицо?',...
    'Что идет за поездом?','Что с небес на землю льётся?',...
    'Кто сливе родственник?', 'Тонкое различие в чём-либо..'};
answerWordBasa = {[19 13 16 3 1], [19 3 6 25 1], [14 6 13 16 12], [9 1 14 16 12],...
                  [9 1 14 16 12], [26 13 33 17 1], [26 17 1 4 1], [14 1 19 12 1],...
                  [3 1 4 16 15], [5 16 8 5 30], [1 13 29 25 1], [15 32 1 15 19]};
if nargin == 3
    uesrWord = varargin{1};
    ind = varargin{2};
    isLetterInBox = varargin{3};
else
    r = randi([1 12]);
    question = questionBasa{1,r};
    ind = [1 1 1 1 1];
    isLetterInBox = [0 0 0 0 0];
    %   answerWord = [19 13 16 3 1];
    answerWord = answerWordBasa{1,r};
    uesrWord = [0 0 0 0 0];
end
hold on
title(question);            % вопрос
% рисуем поле и букву, если она была
for k = 1:5
    p1 = plot(k,0,'sk');
    xlim([0.5 5.5])
    set(p1,'MarkerSize',60,'ButtonDownFcn',@letterInBoxes);
    if uesrWord(1,k) ~= 0
        set(text(k-0.2,0.05,letters(1,uesrWord(1,k))),'FontSize',40,'Margin',0.1);
    end
end
% подсказка для пользователя
xlabel('red == wrong                 green == right')
% пропуск вопроса
set(text(5,0.9,'next->'),'ButtonDownFcn',@fieldOfDream,'EdgeColor','k');
set(text(0.6,0.9,'EXIT'),'ButtonDownFcn',@exit,'Color','r','EdgeColor','r');
end




function letterInBoxes(varargin)
global ind;
global letters;
global uesrWord;
global answerWord;
global isLetterInBox;
my1 = varargin{1};
x = get(my1,'XData');
% если буква уже есть, то пеерерисовываем поле, заполняя его ответом
% пользователя
if isLetterInBox(1,x) ~= 0
    cla;
    uesrWord(1,x) = 0;
    fieldOfDream(uesrWord,ind,isLetterInBox);
end
% выбираем букву и выводим ее
letter = letters{1,ind(1,x)};
t = text(x-0.2,0.05,letter);
set(t,'FontSize',40,'Margin',0.1);
% заполняем ответ пользователя и вектор проверки
uesrWord(1,x) = ind(1,x);
isLetterInBox(1,x) = 1;
% если буква верная, то ее цвет зеленый, иначе - красный
if uesrWord(1,x) == answerWord(1,x)
    set(t,'Color','g')
else
    set(t,'Color','r')
end
% если ответы совпадают, выводим "ВЕРНО!" и предлагаем начать новую игру
if uesrWord == answerWord
    winTXT = text(2,0.6,'ВЕРНО!');
    set(winTXT,'FontSize',35,'Color',[0 0.9 0.35]);
    newGame = text(1.75,-0.75,'<<Начать новую игру>>');
    set(newGame,'FontSize',15,'Color','k');
    set(newGame,'ButtonDownFcn',@fieldOfDream);
    starL = plot(1.25,0.6,'pb');
    starR = plot(4.75,0.6,'pb');
    xlim([0.5 5.5])
    ylim([-1 1])
    while 1 < 2
        hold on;
        for k = 5:5:50
            set(starL,'MarkerSize',k);
            set(starR,'MarkerSize',k);
            pause(0.017)
        end
        for k = 50:-5:5
            set(starL,'MarkerSize',k);
            set(starR,'MarkerSize',k);
            pause(0.017)
        end
    end
end
% границы индекса
ind(1,x) = ind(1,x) + 1;
if ind(1,x) == 34
    ind(1,x) = 1;
end

end




function exit(varargin)
close all;
end