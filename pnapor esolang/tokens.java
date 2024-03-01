import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public enum TokenType {
    // Literals
    NUMBER,
    STRING,
    BOOLEAN,
    ARRAY,
    NULL,

    // References
    IDENTIFIER,

    // Arithmetical operators
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    MODULO,
    INCREMENT,
    DECREMENT,

    // Comparison operators
    EQUAL,
    NOT_EQUAL,
    GREATER_THAN,
    LESS_THAN,
    GREATER_THAN_OR_EQUAL,
    LESS_THAN_OR_EQUAL,

    // Logical operators
    AND,
    OR,
    NOT,

    // Assignment operators
    ASSIGNMENT,
    ASSIGNMENT_ADD,
    ASSIGNMENT_SUB,
    ASSIGNMENT_MUL,
    ASSIGNMENT_DIV,
    ASSIGNMENT_MOD,

    // Other operators
    COMMA,
    PARENTHESIS,
    SQUARE_BRACKET,
    CURLY_BRACKET,
    SEMICOLON,

    // Keywords
    IF,
    ELSE,
    WHILE,
    RETURN,
    BREAK,
    CONTINUE,

    // Utils
    LITERAL,
    ARRAY_INDEXING,
    FUNCTION_CALL,
    FUNCTION_DECLARATION,
    FUNCTION;

    private static final List<TokenType> LITERAL_TYPES = new ArrayList<>(Arrays.asList(NUMBER, STRING, BOOLEAN, ARRAY, NULL));

    public static boolean isLiteralType(TokenType tokenType) {
        return LITERAL_TYPES.contains(tokenType);
    }

    private static final int[] TOKEN_PRIORITY_TABLE = {
        0,  // NUMBER
        0,  // STRING
        0,  // BOOLEAN
        0,  // ARRAY
        0,  // NULL

        0,  // IDENTIFIER

        8,  // PLUS
        8,  // MINUS
         9,  // MULTIPLY
         9,  // DIVIDE
         9,  // MODULO
        11, // INCREMENT
        11, // DECREMENT

        6,  // EQUAL
        6,  // NOT_EQUAL
        7,  // GREATER_THAN
        7,  // LESS_THAN
        7,  // GREATER_THAN_OR_EQUAL
        7,  // LESS_THAN_OR_EQUAL

        5,  // AND
        4,  // OR
        10, // NOT

        3,  // ASSIGNMENT
        3,  // ASSIGNMENT_ADD
        3,  // ASSIGNMENT_SUB
        3,  // ASSIGNMENT_MUL
        3,  // ASSIGNMENT_DIV
        3,  // ASSIGNMENT_MOD

        0,  // COMMA
        12, // PARENTHESIS
        12, // SQUARE_BRACKET
        12, // CURLY_BRACKET
        0,  // SEMICOLON

        1,  // IF
        2,  // ELSE
        1,  // WHILE
        1,  // RETURN
        1,  // BREAK
        1,  // CONTINUE

        0,  // LITERAL
        0,  // ARRAY_INDEXING
        0,  // FUNCTION_CALL
        0,  // FUNCTION_DECLARATION
        0,  // FUNCTION
    };

    public static final int MAX_PRIORITY = TOKEN_PRIORITY_TABLE[PARENTHESIS.ordinal()];

    private static final TokenType[][] EXPRESSION_RESULT_TYPES_TABLE = {
        { NUMBER },                                   // NUMBER
        { STRING },                                   // STRING
        { BOOLEAN },                                  // BOOLEAN
       
