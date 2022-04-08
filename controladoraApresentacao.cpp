#include "conio.h"
#include "controladoraApresentacao.h"
#include <string>

void CntrApresentacaoControle::executar()
{


  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Acessar sistema.";
  char texto3[] = "2 - Cadastrar usuario.";
  char texto4[] = "3 - Acessar dados sobre excursões.";
  char texto5[] = "4 - Acessar dados sobre sessões.";
  char texto6[] = "5 - Acessar dados sobre avaliações.";
  char texto7[] = "6 - Encerrar execução do sistema.";


  char texto8[] = "Selecione um dos servicos : ";
  char texto9[] = "1 - Selecionar servicos de usuarios.";
  char texto10[] = "2 - Selecionar servicos relacionados a excursões.";
  char texto11[] = "3 - Selecionar servicos relacionados a sessões.";
  char texto12[] = "4 - Selecionar servicos relacionados a avaliações.";
  char texto13[] = "5 - Encerrar sessao.";

  char texto14[] = "Falha na autenticação. Digite algo para continuar.";
  
  int campo;

  bool apresentar = true;

  while (apresentar)
  {
    if (apresentar == false) {
        return;
    }
    CLR_SCR;// Limpa janela.
    cout << texto1 << endl;      // Imprime nome do campo.
    cout << texto2 << endl;   // Imprime nome do campo.
    cout << texto3 << endl;   // Imprime nome do campo.
    cout << texto4 << endl;   // Imprime nome do campo.
    cout << texto5 << endl;   // Imprime nome do campo.
    cout << texto6 << endl;  // Imprime nome do campo.
    cout << texto7 << endl;  // Imprime nome do campo.

    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

    switch (campo)
    {
    case 1:
      if (cntrApresentacaoAutenticacao->autenticar(&email))
      {
        if (apresentar == false) {
            return;
        }
        while (true)
        {
          CLR_SCR;                                             // Limpa janela.
          cout << texto8 << endl;  // Imprime nome do campo.
          cout <<   texto9 << endl;    // Imprime nome do campo.
          cout <<  texto10 << endl;   // Imprime nome do campo.
          cout <<  texto11 << endl;   // Imprime nome do campo.
          cout <<  texto12 << endl;   // Imprime nome do campo.
          cout <<   texto13 << endl;  // Imprime nome do campo.

          
          campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
          

          switch (campo)
          {
          case 1:
            cntrApresentacaoUsuario->executar(email); // Solicita servi�o de pessoal.
            break;
          case 2:
            cntrApresentacaoExcursao->executar(email);
            break;
          case 3:
            cntrApresentacaoSessao->executar(email); // Solicita servi�o de produto financeiro.
            break;
          case 4:
            cntrApresentacaoAvaliacao->executar(email); // Solicita servi�o de produto financeiro.
            break;
          case 5:
            return;
          }
        }
      }
      else
      {
        CLR_SCR;                                       // Limpa janela.
        cout <<  texto14<< endl; // Imprime mensagem.
        getch();                                        // Leitura de caracter digitado.
      }
      break;
    case 2:
      cntrApresentacaoUsuario->cadastrar();
      break;
    case 3:
      cntrApresentacaoExcursao->executar();
      break;
    case 4:
      cntrApresentacaoSessao->executar();
      break;
    case 5:
      cntrApresentacaoAvaliacao->executar();
      break;
    case 6:
      CLR_SCR;
      apresentar = false;
      break;
    }

  }
  return;
}

//--------------------------------------------------------------------------------------------

bool CntrApresentacaoAutenticacao::autenticar(Email *email)
{

  char texto1[] = "Digite o email  : ";
  char texto2[] = "Digite a senha: ";
  char texto3[] = "Dado em formato incorreto. Digite algo.";
  char texto4[]= "1 - Tentar novamente.";
  char texto5[]= "2 - Voltar para a tela inicial.";
  char texto6[] = "Autenticado com sucesso.";

  char campo1[80];
  char campo2[80];
  int campo;
  Senha senha;

   bool apresentar = true;
  while (apresentar)
  {
    if (apresentar == false) {
      return false;
    }

    CLR_SCR;
    cout << texto1<< endl; 
    cin >> campo1;
    cout << texto2<< endl; 
    cin >> campo2;

    try
    {
      email->setEmail(string(campo1));
      senha.setSenha(string(campo2));
      
      if (cntr->autenticar(*email, senha))
      {
        cout << texto6 << endl;
        getch();
        return true;        
      } // Solicita servi�
      break;                          
    }
    catch (invalid_argument &exp)
    { 
      CLR_SCR;                                     // Limpa janela.
      cout << texto3 << endl; // Informa formato incorreto.
      getch(); // L� caracter digitado.
    }
 

  // CLR_SCR;                                                                            // Limpa janela.
  // cout << texto3 <<"\n"<< endl;                                                             // Informa formato incorreto.
  cout << texto4 <<endl;
  cout << texto5 << endl;

  campo = getch() - 48;

  switch (campo){
    case 1: 
      continue;// Solicita servi�o de autentica��o.
      case 2:
        apresentar = false;
        return false;
    }
  }
  return true;      
}
//--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::executar(Email email)
{

  // Mensagens a serem apresentadas na tela de sele��o de servi�o..

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Editar Dados.";
  char texto3[] = "2 - Excluir Cadastro.";
  char texto4[] = "3 - Retornar.";

  int campo; // Campo de entrada.

  bool apresentar = true; // Controle de la�o.

  while (apresentar)
  {

    // Apresenta tela de sela��o de servi�o.

    CLR_SCR;                                           // Limpa janela.
    cout << texto1 << endl;     // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cout << texto3 << endl; // Imprime nome do campo.
    cout << texto4 << endl; // Imprime nome do campo.

    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.

    switch (campo)
    {
    case 1:
      editarUsuario();
      break;
    case 2:
      // editarDadosUsuario();
      break;
    case 3:
      apresentar = false;
      break;
    }
  }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::cadastrar()
{

  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Nome            :";
  char texto3[] = "Email           :";
  char texto4[] = "Senha           :";
  char texto5[] = "Dados em formato incorreto. Digite algo.";
  char texto6[] = "Sucesso no cadastramento. Digite algo.";
  char texto7[] = "Falha no cadastramento. Digite algo.";

  char campo1[80], campo2[80], campo3[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.

  Nome nome;
  Email email;
  Senha senha;


  // Apresenta tela de cadastramento.

  CLR_SCR; // Limpa janela.

  cout << texto1 << endl;     // Imprime nome do campo.
  cout << texto2 << endl; // Imprime nome do campo.
  cin.getline(campo1,sizeof(campo1));
  cout <<  texto3  << endl; // Imprime nome do campo.
  cin >> campo2;                                    // L� valor do campo.
  cout << texto4 << endl; // Imprime nome do campo.
  cin >> campo3;                                    // L� valor do campo.
  try
  {
    nome.setNome(string(campo1));
    email.setEmail(string(campo2));
    senha.setSenha(string(campo3));
  }
  catch (invalid_argument &exp)
  {
    cout << texto5 << endl; // Informa formato incorreto.
    getch();                // Leitura de caracter digitado.
    return;
  }

  // Instancia e inicializa entidades.

  Usuario usuario;

  usuario.setNome(nome);
  usuario.setEmail(email);
  usuario.setSenha(senha);

  if (cntrServicoUsuario->cadastrarUsuario(usuario))
  {
    cout << texto6 << endl; // Informa sucesso.
    getch();
    return;
  }
  cout << texto7 << endl; // Informa falha.
  getch();
  return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoUsuario::consultarDadosUsuario()
{

  // Mensagens a serem apresentadas na tela de apresenta��o de dados pessoais.


  char texto[] = "Servico consultar dados pessoais nao implementado. Digite algo."; // Mensagem a ser apresentada.
  CLR_SCR;                                                                          // Limpa janela.
  cout << texto << endl;                                     // Imprime nome do campo.
  getch();
}

void CntrApresentacaoUsuario::editarUsuario()
{

  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Nome            :";
  char texto3[] = "Senha           :";
  char texto4[] = "Dados em formato incorreto. Digite algo.";
  char texto5[] = "Sucesso na alteração. Digite algo.";
  char texto6[] = "Falha na alteração. Digite algo.";

  char campo1[80], campo2[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.

  Nome nome;
  Senha senha;

  // Apresenta tela de cadastramento.

  CLR_SCR; // Limpa janela.

  cout <<  texto1 << endl;     // Imprime nome do campo.
  cout <<  texto2 << endl; // Imprime nome do campo.
  cin >> campo1;                                    // L� valor do campo.
  cout <<  texto3 << endl; // Imprime nome do campo.
  cin >> campo2;                                    // L� valor do campo.
  try
  {
    nome.setNome(string(campo1));
    senha.setSenha(string(campo2));
  }
  catch (invalid_argument &exp)
  {
    cout << texto4 << endl; // Informa formato incorreto.
                                              // Desabilita eco.
    getch();                                           // Leitura de caracter digitado.
                                                // Habilita eco.
    return;
  }

  // Instancia e inicializa entidades.

  Usuario usuario;

  usuario.setNome(nome);
  usuario.setSenha(senha);

  if (cntrServicoUsuario->editarUsuario(usuario))
  {
    cout << texto5 << endl; // Informa sucesso.
    
    getch();
    
    return;
  }

  cin >> texto6; // Informa falha.
  
  getch();
  

  return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursao::executar()
{

  // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Consultar excursões.";
  char texto3[] = "2 - Retornar.";

  int campo; // Campo de entrada.

  bool apresentar = true; // Controle de la�o.

  while (apresentar)
  {

    // Apresenta tela simplificada de produtos financeiros.

    CLR_SCR;                                           // Limpa janela.
    cout << texto1 << endl;     // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cout << texto3 << endl; // Imprime nome do campo.
    
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    
    switch (campo)
    {
    case 1:
      // listarExcursoes();
      break;
    case 2:
      apresentar = false;
      break;
    }
  }
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoExcursao::executar(Email email)
{

  // Mensagens a serem apresentadas tela completa de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Cadastrar Excursão.";
  char texto3[] = "2 - Consultar Excursão.";
  char texto4[] = "3 - Editar Excursão.";
  char texto5[] = "4 - Excluir Excursão.";
  char texto6[] = "5 - Retornar.";

  int campo; // Campo de entrada.

   // Habilita eco.

  bool apresentar = true; // Controle de la�o.

   // Habilita eco.

  while (apresentar)
  {

    // Apresenta tela completa de produtos financeiros.

    CLR_SCR;                                            // Limpa janela.
    cout << texto1 << endl;      // Imprime nome do campo.
    cout << texto2 << endl;  // Imprime nome do campo.
    cout << texto3 << endl;  // Imprime nome do campo.
    cout << texto4 << endl;  // Imprime nome do campo.
    cout << texto5 << endl;  // Imprime nome do campo.
    cout << texto6 << endl; // Imprime nome do campo.
    
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    

    switch (campo)
    {
    case 1:
      cadastrarExcursao(email);
      break;
    case 2:
      consultarExcursao(email);
      break;
    case 3:
      editarExcursao(email);
      break;
    case 4:
      descadastrarExcursao(email);
      break;
    case 5:
      apresentar = false;
      break;
    }
  }
}

void CntrApresentacaoExcursao::consultarExcursao(Email email)
{
  return;
}

void CntrApresentacaoExcursao::cadastrarExcursao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Código          :";
  char texto3[] = "Título          :";
  // char texto4[] = "Nota            :";
  char texto5[] = "Cidade          :";
  char texto5b[] = "Duração         :";
  char texto5c[] = "Descrição       :";
  char texto5d[] = "Endereço        :";
  char texto6[] = "Dados em formato incorreto. Digite algo.";
  char texto7[] = "Sucesso no cadastramento. Digite algo.";
  char texto8[] = "Falha no cadastramento. Digite algo.";

  char campo0[80], campo1[80], /*campo2[80],*/ campo3[80], campo4[80], campo5[80], campo6[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.
  // Codigo codigo;
  Titulo titulo;
  // Nota nota;
  Cidade cidade;
  Duracao duracao;
  Descricao descricao;
  Endereco endereco;
  
  // Apresenta tela de cadastramento.
  
  CLR_SCR; // Limpa janela.

  cout <<  texto1 << endl; // Imprime nome do campo.
  // cout << texto2 << endl; // Imprime nome do campo.
  // cin >> campo0;                                    // L� valor do campo.
  cout << texto3 << endl; // Imprime nome do campo.
  cin >> campo1;                                    // L� valor do campo.
  // cout << texto4 << endl; // Imprime nome do campo.
  // cin >> campo2;                                    // L� valor do campo.
  // int icampo2 = atoi(campo2);
  cout << texto5 << endl;   // Imprime nome do campo.
  cin >> campo3;                                      // L� valor do campo.
  cout << texto5b << endl;  // Imprime nome do campo.
  cin >> campo4;                                      // L� valor do campo.
  cout << texto5c << endl;  // Imprime nome do campo.
  cin >> campo5;                                      // L� valor do campo.
  cout << texto5d << endl; // Imprime nome do campo.
  cin >> campo6;                                      // L� valor do campo.
  try
  {
    // codigo.setCodigo(codigo.getDigitoVerificador(nextId));
    // codigo.setCodigo(campo0);
    titulo.setTitulo(campo1);
    // nota.setNota(icampo2);
    cidade.setCidade(campo3);
    duracao.setDuracao(campo4);
    descricao.setDescricao(campo5);
    endereco.setEndereco(campo6);
  }
  catch (invalid_argument &exp)
  {
    cout << texto6 << endl; // Informa formato incorreto.
                                               // Desabilita eco.
    getch();                                            // Leitura de caracter digitado.
                                                 // Habilita eco.
    return;
  }

  // Instancia e inicializa entidades.

  Excursao excursao;

  // excursao.setCodigo(codigo);
  excursao.setTitulo(titulo);
  // excursao.setNota(nota);
  excursao.setCidade(cidade);
  excursao.setDuracao(duracao);
  excursao.setDescricao(descricao);
  excursao.setEndereco(endereco);

  if (cntrServicoExcursao->cadastrarExcursao(excursao, email))
  {
    cout << texto7 << endl; // Informa sucesso.
    
    getch();
    
    return;
  }

  cout << texto8 << endl; // Informa falha.
  
  getch();
  
  return;
}

void CntrApresentacaoExcursao::editarExcursao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Qual o Código da Excursão que você deseja alterar?  :";
  char texto3[] = "Título          :";
  // char texto4[] = "Nota            :";
  char texto5[] = "Cidade          :";
  char texto6[] = "Duração         :";
  char texto7[] = "Descrição       :";
  char texto8[] = "Endereço        :";
  char texto9[] = "Dados em formato incorreto. Digite algo.";
  char texto10[] = "Sucesso na alteração. Digite algo.";
  char texto11[] = "Falha na alteração. Digite algo.";

  char campo0[80], campo1[80], /*campo2[80],*/ campo3[80], campo4[80], campo5[80], campo6[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.
  Codigo codigo;
  Titulo titulo;
  // Nota nota;
  Cidade cidade;
  Duracao duracao;
  Descricao descricao;
  Endereco endereco;



  // Apresenta tela de cadastramento.

  CLR_SCR; // Limpa janela.

  cout << texto1 << endl;     // Imprime nome do campo.
  cout << texto2 << endl; // Imprime nome do campo.
  cin >> campo0;                                    // L� valor do campo.
  cout << texto3 << endl; // Imprime nome do campo.
  cin >> campo1;                                    // L� valor do campo.
  // cout << texto4 << endl; // Imprime nome do campo.
  // cin >> campo2;                                    // L� valor do campo.
  // int icampo2 = atoi(campo2);
  cout << texto5 << endl;  // Imprime nome do campo.
  cin >> campo3;                                     // L� valor do campo.
  cout << texto6 << endl; // Imprime nome do campo.
  cin >> campo4;                                     // L� valor do campo.
  cout << texto7 << endl; // Imprime nome do campo.
  cin >> campo5;                                     // L� valor do campo.
  cout << texto8 << endl; // Imprime nome do campo.
  cin >> campo6;                                     // L� valor do campo.
  try
  {
    // codigo.setCodigo(codigo.getDigitoVerificador(nextId));
    codigo.setCodigo(campo0);
    titulo.setTitulo(campo1);
    // nota.setNota(icampo2);
    cidade.setCidade(campo3);
    duracao.setDuracao(campo4);
    descricao.setDescricao(campo5);
    endereco.setEndereco(campo6);
  }
  catch (invalid_argument &exp)
  {
    cout << texto9 << endl; // Informa formato incorreto.
                                               // Desabilita eco.
    getch();                                            // Leitura de caracter digitado.
                                                 // Habilita eco.
    return;
  }

  // Instancia e inicializa entidades.

  Excursao excursao;

  excursao.setCodigo(codigo);
  excursao.setTitulo(titulo);
  // excursao.setNota(nota);
  excursao.setCidade(cidade);
  excursao.setDuracao(duracao);
  excursao.setDescricao(descricao);
  excursao.setEndereco(endereco);

  if (cntrServicoExcursao->editarExcursao(excursao, email))
  {
    cout << texto10 << endl; // Informa sucesso.
    
    getch();
    
    return;
  }

  cout << texto11 << endl; // Informa falha.
  
  getch();
  
  return;
}

void CntrApresentacaoExcursao::descadastrarExcursao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.
  char texto1[] = "Descadastrar uma excursao: ";
  char texto2[] = "Código          :";
  char texto3[] = "Dado em formato incorreto. Digite algo.";
  char texto4[] = "Sucesso no descadastramento. Digite algo.";
  char texto5[] = "Falha no descadastramento. Digite algo.";

  char campo1[80];

  Codigo codigo;


  CLR_SCR;                                           // Limpa janela.
  cout << texto1 << endl;     // Imprime nome do campo.
  cout << texto2 << endl; // Imprime nome do campo.
  cin >> campo1;                                    // L� valor do campo.

  try
  {
    codigo.setCodigo(campo1);
  }
  catch (invalid_argument &exp)
  {
    cout << texto3 << endl; // Informa falha.
                                              // Desabilita eco.
    getch();                                           // Leitura de caracter digitado.
                                                // Habilita eco.
    return;
  }

  if (cntrServicoExcursao->descadastrarExcursao(codigo, email) && campo1 != "")
  {
    cout << texto4 << endl; // Informa sucesso.
    
    getch();
    
    return;
  }

  cout << texto5 << endl; // Informa falha.
  
  getch();
  
  return;
}

void CntrApresentacaoExcursao::listarExcursoes(Email email)
{
  return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoSessao::executar()
{

  // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Consultar sessões.";
  char texto3[] = "2 - Retornar.";

  int campo; // Campo de entrada.


   // Habilita eco.

  bool apresentar = true; // Controle de la�o.

  while (apresentar)
  {

    // Apresenta tela simplificada de produtos financeiros.

    CLR_SCR;                                           // Limpa janela.
    cout << texto1 << endl;     // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cout << texto3 << endl; // Imprime nome do campo.
    
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    

    switch (campo)
    {
    case 1:
      // consultarProdutoInvestimento();
      break;
    case 2:
      apresentar = false;
      break;
    }
  }
}

void CntrApresentacaoSessao::executar(Email email)
{

  // Mensagens a serem apresentadas tela completa de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Cadastar sessão.";
  char texto3[] = "2 - Consultar sessão.";
  char texto4[] = "3 - Editar sessão.";
  char texto5[] = "4 - Excluir sessão.";
  char texto6[] = "5 - Retornar.";

  int campo; // Campo de entrada.



   // Habilita eco.

  bool apresentar = true; // Controle de la�o.

   // Habilita eco.

  while (apresentar)
  {

    // Apresenta tela completa de produtos financeiros.

    CLR_SCR;                                            // Limpa janela.
    cout << texto1 << endl;      // Imprime nome do campo.
    cout << texto2 << endl;  // Imprime nome do campo.
    cout << texto3 << endl;  // Imprime nome do campo.
    cout << texto4 << endl;  // Imprime nome do campo.
    cout << texto5 << endl;  // Imprime nome do campo.
    cout << texto6 << endl; // Imprime nome do campo.
    
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    

    switch (campo)
    {
    case 1:
      cadastrarSessao(email);
      break;
    case 2:
      consultarSessao(email);
      break;
    case 3:
      editarSessao(email);
      break;
    case 4:
      descadastrarSessao(email);
      break;
    case 5:
      apresentar = false;
      break;
    }
  }
}

void CntrApresentacaoSessao::consultarSessao(Email email)
{
  return;
}

void CntrApresentacaoSessao::cadastrarSessao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Código              :";
  char texto3[] = "Data                :";
  char texto4[] = "Horario             :";
  char texto5[] = "Idioma              :";
  char texto6[] = "Código da Excursão  :";
  char texto7[] = "Dados em formato incorreto. Digite algo.";
  char texto8[] = "Sucesso no cadastramento. Digite algo.";
  char texto9[] = "Falha no cadastramento. Digite algo.";

  char campo1[80], campo2[80], campo3[80], campo4[80], campo5[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.
  Codigo codigo;
  Data data;
  Horario horario;
  Idioma idioma;
  Codigo codigoExcursao;



  // Apresenta tela de cadastramento.

  CLR_SCR; // Limpa janela.

  cout << texto1 << endl;     // Imprime nome do campo.
  cout << texto2 << endl; // Imprime nome do campo.
  cin >> campo1;                                    // L� valor do campo.
  cout << texto3 << endl; // Imprime nome do campo.
  cin >> campo2;                                    // L� valor do campo.
  cout << texto4 << endl; // Imprime nome do campo.
  cin >> campo3;                                    // L� valor do campo.
  int icampo2 = atoi(campo3);
  cout << texto5 << endl;  // Imprime nome do campo.
  cin >> campo4;                                     // L� valor do campo.
  cout << texto6 << endl; // Imprime nome do campo.
  cin >> campo5;                                     // L� valor do campo.

  try
  {
    // codigo.setCodigo(codigo.getDigitoVerificador(nextId));
    codigo.setCodigo(campo1);
    data.setData(campo2);
    horario.setHorario(campo3);
    idioma.setIdioma(campo4);
    codigoExcursao.setCodigo(campo5);
  }
  catch (invalid_argument &exp)
  {
    cout << texto7 << endl; // Informa formato incorreto.
                                               // Desabilita eco.
    getch();                                            // Leitura de caracter digitado.
                                                 // Habilita eco.
    return;
  }

  // Instancia e inicializa entidades.

  Sessao sessao;

  sessao.setCodigo(codigo);
  sessao.setData(data);
  sessao.setHorario(horario);
  sessao.setIdioma(idioma);
  // sessao.setCodigo(codigoExcursao);

  if (cntrServicoExcursao->cadastrarSessao(sessao, email, codigoExcursao))
  {
    cout << texto8 << endl; // Informa sucesso.
    
    getch();
    
    return;
  }

  cout << texto9 << endl; // Informa falha.
  
  getch();
  
  return;
}

void CntrApresentacaoSessao::editarSessao(Email email)
{
  return;
}

void CntrApresentacaoSessao::descadastrarSessao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.
  char texto1[] = "Descadastrar uma sessão: ";
  char texto2[] = "Código da sessão :";
  char texto3[] = "Dado em formato incorreto. Digite algo.";
  char texto4[] = "Sucesso no descadastramento. Digite algo.";
  char texto5[] = "Falha no descadastramento. Digite algo.";

  char campo1[80];

  Codigo codigo;


  CLR_SCR;                                           // Limpa janela.
  cout << texto1 << endl;     // Imprime nome do campo.
  cout << texto2 << endl; // Imprime nome do campo.
  cin >> campo1;                                    // L� valor do campo.

  try
  {
    codigo.setCodigo(campo1);
  }
  catch (invalid_argument &exp)
  {
    cout << texto3 << endl; // Informa falha.
                                              // Desabilita eco.
    getch();                                           // Leitura de caracter digitado.
                                                // Habilita eco.
    return;
  }

  if (cntrServicoExcursao->descadastrarExcursao(codigo, email) && campo1 != "")
  {
    cout << texto4 << endl; // Informa sucesso.
    
    getch();
    
    return;
  }

  cout << texto5 << endl; // Informa falha.
  
  getch();
  
  return;
}

void CntrApresentacaoSessao::listarSessoes(Email email)
{
  return;
}

//--------------------------------------------------------------------------------------------

void CntrApresentacaoAvaliacao::executar()
{

  // Mensagens a serem apresentadas na tela simplificada de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Consultar avaliações.";
  char texto3[] = "2 - Retornar.";

  int campo; // Campo de entrada.


   // Habilita eco.

  bool apresentar = true; // Controle de la�o.

  while (apresentar)
  {

    // Apresenta tela simplificada de produtos financeiros.

    CLR_SCR;                                           // Limpa janela.
    cout << texto1 << endl;     // Imprime nome do campo.
    cout << texto2 << endl; // Imprime nome do campo.
    cout << texto3 << endl; // Imprime nome do campo.
    
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    

    switch (campo)
    {
    case 1:
      // consultarProdutoInvestimento();
      break;
    case 2:
      apresentar = false;
      break;
    }
  }
}

void CntrApresentacaoAvaliacao::executar(Email email)
{

  // Mensagens a serem apresentadas tela completa de produtos financeiros.

  char texto1[] = "Selecione um dos servicos : ";
  char texto2[] = "1 - Cadastrar Avaliação.";
  char texto3[] = "2 - Consultar Avaliação.";
  char texto4[] = "3 - Editar Avaliação.";
  char texto5[] = "4 - Excluir Avaliação.";
  char texto6[] = "5 - Retornar.";

  int campo; // Campo de entrada.



   // Habilita eco.

  bool apresentar = true; // Controle de la�o.

   // Habilita eco.

  while (apresentar)
  {

    // Apresenta tela completa de produtos financeiros.

    CLR_SCR;                                            // Limpa janela.
    cout << texto1 << endl;      // Imprime nome do campo.
    cout << texto2 << endl;  // Imprime nome do campo.
    cout << texto3 << endl;  // Imprime nome do campo.
    cout << texto4 << endl;  // Imprime nome do campo.
    cout << texto5 << endl;  // Imprime nome do campo.
    cout << texto6 << endl; // Imprime nome do campo.
    
    campo = getch() - 48; // Leitura do campo de entrada e convers�o de ASCII.
    

    switch (campo)
    {
    case 1:
      // consultarConta(email);
      break;
    case 2:
      // cadastrarProdutoInvestimento(email);
      break;
    case 3:
      // descadastrarProdutoInvestimento(email);
      break;
    case 4:
      // consultarProdutoInvestimento(email);
      break;
    case 5:
      apresentar = false;
      break;
    }
  }
}

void CntrApresentacaoAvaliacao::consultarAvaliacao(Email email)
{
  return;
}

void CntrApresentacaoAvaliacao::cadastrarAvaliacao(Email email)
{
  // Mensagens a serem apresentadas na tela de cadastramento.

  char texto1[] = "Preencha os seguintes campos: ";
  char texto2[] = "Código              :";
  char texto3[] = "Nota                :";
  char texto4[] = "Descricao             :";
  char texto5[] = "Código da Excursão  :";
  char texto6[] = "Dados em formato incorreto. Digite algo.";
  char texto7[] = "Sucesso no cadastramento. Digite algo.";
  char texto8[] = "Falha no cadastramento. Digite algo.";

  char campo1[80], campo2[80], campo3[80], campo4[80]; // Cria campos para entrada dos dados.

  // Instancia os dom�nios.
  Codigo codigo;
  Nota nota;
  Descricao descricao;
  Codigo codigoExcursao;


  // Apresenta tela de cadastramento.

  CLR_SCR; // Limpa janela.

  cout << texto1 << endl;     // Imprime nome do campo.
  cout << texto2 << endl; // Imprime nome do campo.
  cin >> campo1;                                    // L� valor do campo.
  cout << texto3 << endl; // Imprime nome do campo.
  cin >> campo2;                                    // L� valor do campo.
  int icampo2 = atoi(campo2);

  cout << texto4 << endl; // Imprime nome do campo.
  cin >> campo3;                                    // L� valor do campo.
  cout << texto5 << endl; // Imprime nome do campo.
  cin >> campo4;                                    // L� valor do campo.

  try
  {
    // codigo.setCodigo(codigo.getDigitoVerificador(nextId));
    codigo.setCodigo(campo1);
    nota.setNota(icampo2);
    descricao.setDescricao(campo3);
    codigoExcursao.setCodigo(campo4);
  }
  catch (invalid_argument &exp)
  {
    cout << texto6 << endl; // Informa formato incorreto.
                                               // Desabilita eco.
    getch();                                            // Leitura de caracter digitado.
                                                 // Habilita eco.
    return;
  }

  // Instancia e inicializa entidades.

  Avaliacao avaliacao;

  avaliacao.setCodigo(codigo);
  avaliacao.setNota(nota);
  avaliacao.setDescricao(descricao);
  // avaliacao.setIdioma(idioma);
  // sessao.setCodigo(codigoExcursao);

  if (cntrServicoExcursao->cadastrarAvaliacao(avaliacao, email, codigoExcursao))
  {
    cout << texto7 << endl; // Informa sucesso.
    
    getch();
    
    return;
  }

  cout << texto8 << endl; // Informa falha.
  
  getch();
  
  return;
}

void CntrApresentacaoAvaliacao::editarAvaliacao(Email email)
{
  return;
}

void CntrApresentacaoAvaliacao::descadastrarAvaliacao(Email email)
{
  return;
}

void CntrApresentacaoAvaliacao::listarAvaliacoes(Email email)
{
  return;
}