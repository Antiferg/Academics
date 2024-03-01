import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public enum TokenType {
    NUMBER,
    STRING,
    BOOLEAN,
    ARRAY,
    NULL,
    IDENTIFIER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    MODULO,
    INCREMENT,
    DECREMENT,
    EQUAL,
    NOT_EQUAL,
    GREATER_THAN,
    LESS_THAN,
    GREATER_THAN_OR_EQUAL,
    LESS_THAN_OR_EQUAL,
    AND,
    OR,
    NOT,
    ASSIGNMENT,
    ASSIGNMENT_ADD,
    ASSIGNMENT_SUB,
    ASSIGNMENT_MUL,
    ASSIGNMENT_DIV,
    ASSIGNMENT_MOD,
    COMMA,
    PARENTHESIS,
    SQUARE_BRACKET,
    CURLY_BRACKET,
    SEMICOLON,
    IF,
    ELSE,
    WHILE,
    RETURN,
    BREAK,
    CONTINUE,
    LITERAL,
    ARRAY_INDEXING,
    FUNCTION_CALL,
    FUNCTION_DECLARATION,
    FUNCTION;

    private static final int MAX_PRIORITY = tokenPriorityTable[PARENTHESIS.ordinal()];

    private static final int[] tokenPriorityTable = {
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

    public static boolean isLiteralType(TokenType tokenType) {
        return tokenType == NUMBER ||
                tokenType == STRING ||
                tokenType == BOOLEAN ||
                tokenType == ARRAY ||
                tokenType == NULL;
    }

    public static int getPriority(TokenType tokenType) {
        int typePriority = tokenPriorityTable[tokenType.ordinal()];
        return typePriority == 0 ? 0 : typePriority;
    }

    public static int getMaxPriority() {
        return MAX_PRIORITY;
    }

    public static List<TokenType> getExpressionResultTypes(TokenType tokenType) {
        TokenType[] types = expressionResultTypesTable[tokenType.ordinal()];
        return
    types != null ? Arrays.asList(types) : null;
    }
    public static List<TokenType> getSupportedOperandTypes(TokenType tokenType) {
    TokenType[] types = supportedOperandTypesTable[tokenType.ordinal()];
    return Arrays.asList(types);
}

private static final TokenType[][] expressionResultTypesTable = {
        { NUMBER },                         // NUMBER
        { STRING },                         // STRING
        { BOOLEAN },                        // BOOLEAN
        { ARRAY },                          // ARRAY
        { NULL },                           // NULL
        { LITERAL },                        // IDENTIFIER
        { NUMBER, STRING, ARRAY },          // PLUS
        { NUMBER },                         // MINUS
        { NUMBER },                         // MULTIPLY
        { NUMBER },                         // DIVIDE
        { NUMBER },                         // MODULO
        { NUMBER },                         // INCREMENT
        { NUMBER },                         // DECREMENT
        { BOOLEAN },                        // EQUAL
        { BOOLEAN },                        // NOT_EQUAL
        { BOOLEAN },                        // GREATER_THAN
        { BOOLEAN },                        // LESS_THAN
        { BOOLEAN },                        // GREATER_THAN_OR_EQUAL
        { BOOLEAN },                        // LESS_THAN_OR_EQUAL
        { BOOLEAN },                        // AND
        { BOOLEAN },                        // OR
        { BOOLEAN },                        // NOT
        { NUMBER, STRING, BOOLEAN, ARRAY, NULL },    // ASSIGNMENT
        { NUMBER, STRING, ARRAY },           // ASSIGNMENT_ADD
        { NUMBER },                         // ASSIGNMENT_SUB
        { NUMBER },                         // ASSIGNMENT_MUL
        { NUMBER },                         // ASSIGNMENT_DIV
        { NUMBER },                         // ASSIGNMENT_MOD
        { },                                // COMMA
        { NUMBER, STRING, BOOLEAN, ARRAY, NULL },   // PARENTHESIS
        { SQUARE_BRACKET },                 // SQUARE_BRACKET
        { CURLY_BRACKET },                  // CURLY_BRACKET
        { },                                // SEMICOLON
        { },                                // IF
        { },                                // ELSE
        { },                                // WHILE
        { NUMBER, STRING, BOOLEAN, ARRAY, NULL },   // RETURN
        { },                                // BREAK
        { },                                // CONTINUE
        { NUMBER, STRING, BOOLEAN, ARRAY, NULL },    // LITERAL
        { NUMBER, STRING, BOOLEAN, ARRAY, NULL },    // ARRAY_INDEXING
        { NUMBER, STRING, BOOLEAN, ARRAY, NULL },    // FUNCTION_CALL
        { FUNCTION_DECLARATION },           // FUNCTION_DECLARATION
        { FUNCTION },                       // FUNCTION
};

private static final TokenType[][] supportedOperandTypesTable = {
        null,                               // NUMBER
        null,                               // STRING
        null,                               // BOOLEAN
        null,                               // ARRAY
        null,                               // NULL
        null,                               // IDENTIFIER
        { NUMBER, STRING, ARRAY },          // PLUS
        { NUMBER },                         // MINUS
        { NUMBER },                         // MULTIPLY
        { NUMBER },                         // DIVIDE
        { NUMBER },                         // MODULO
        { NUMBER },                         // INCREMENT
        { NUMBER },                         // DECREMENT
        { NUMBER, STRING, BOOLEAN, ARRAY, NULL },    // EQUAL
        { NUMBER, STRING, BOOLEAN, ARRAY, NULL },    // NOT_EQUAL
        { NUMBER },                         // GREATER_THAN
        { NUMBER },                         // LESS_THAN
        { NUMBER },                         // GREATER_THAN_OR_EQUAL
        { NUMBER },                         // LESS_THAN_OR_EQUAL
        { BOOLEAN },                        // AND
        { BOOLEAN },                        // OR
        { BOOLEAN },                        // NOT
        { NUMBER, STRING, BOOLEAN, ARRAY, NULL },    // ASSIGNMENT
        { NUMBER, STRING, ARRAY },           // ASSIGN
        MENT_ADD
        { NUMBER }, // ASSIGNMENT_SUB
        { NUMBER }, // ASSIGNMENT_MUL
        { NUMBER }, // ASSIGNMENT_DIV
        { NUMBER }, // ASSIGNMENT_MOD
        null, // COMMA
        null, // PARENTHESIS
        null, // SQUARE_BRACKET
        null, // CURLY_BRACKET
        null, // SEMICOLON
        null, // IF
        null, // ELSE
        null, // WHILE
        { NUMBER, STRING, BOOLEAN, ARRAY, NULL }, // RETURN
        null, // BREAK
        null, // CONTINUE
        { NUMBER, STRING, BOOLEAN, ARRAY, NULL }, // LITERAL
        { NUMBER, STRING, BOOLEAN, ARRAY, NULL }, // ARRAY_INDEXING
        { NUMBER, STRING, BOOLEAN, ARRAY, NULL }, // FUNCTION_CALL
        null, // FUNCTION_DECLARATION
        null, // FUNCTION
        };
        private TokenType type;
private int priority;
private Object value;
private SourceCodeLocation sourceLocation;
private List<Token> children;

public Token(TokenType type, int basePriority, SourceCodeLocation sourceLocation, Object value) {
    this.type = type;
    int typePriority = tokenPriorityTable[type.ordinal()];
    this.priority = (typePriority == 0) ? 0 : basePriority + typePriority;
    this.value = value;
    this.sourceLocation = sourceLocation;
    this.children = new ArrayList<>();
}

public TokenType getType() {
    return type;
}

public int getPriority() {
    return priority;
}

public Object getValue() {
    return value;
}

public SourceCodeLocation getSourceLocation() {
    return sourceLocation;
}

public List<Token> getChildren() {
    return children;
}

public void setChildren(List<Token> children) {
    this.children = children;
}

@Override
public String toString() {
    StringBuilder sb = new StringBuilder();
    sb.append("<").append(type.name()).append(": ");
    switch (type) {
        case FUNCTION_DECLARATION:
            // value = [body: Token, parameters: List[Token], name: Token]
            String functionName = (String) value[2].getValue();
            List<Token> parameterTokens = (List<Token>) value[1];
            String parameterNames = parameterTokens.stream()
                    .map(parameterToken -> (String) parameterToken.getValue())
                    .collect(Collectors.joining(", "));
            sb.append(functionName).append(" (").append(parameterNames).append(")>");
            break;

        case FUNCTION_CALL:
            // value = [arguments: List[Token], name: Token]
            String callName = (String) value[1].getValue();
            List<Token> argumentTokens = (List<Token>) value[0];
            String argumentValues = argumentTokens.stream()
                    .map(argumentToken -> argumentToken.getValue().toString())
                    .collect(Collectors.joining(", "));
            sb.append(callName).append(" (").append(argumentValues).append(")>");
            break;

        default:
            sb.append(value).append(" (").append(priority).append(")>");
            break;
    }
    return sb.toString();
}
