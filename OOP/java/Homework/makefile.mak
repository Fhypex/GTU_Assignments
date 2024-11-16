# Makefile for Java compilation and execution

# Define the Java compiler
JAVAC = javac

# Define the Java runtime
JAVA = java

# Define the source files
SOURCES = *.java 

# Define the class files (derived from source files)
CLASSES = $(SOURCES:.java=.class)

# Default target (executed when you type 'make')
all: compile run

# Compilation target
compile: $(CLASSES)

# Rule to compile Java files 
%.class: %.java
	$(JAVAC) -cp . *.java # Compile all .java files with classpath

# Run target
run: $(CLASSES)
	$(JAVA) -cp . Main # Run with classpath

# Clean target (remove class files)
clean:
	rm -f *.class